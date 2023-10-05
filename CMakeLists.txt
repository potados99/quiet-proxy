cmake_minimum_required(VERSION 3.26)
project(quiet_practice C)

set(CMAKE_C_STANDARD 11)

# PortAudio가 제대로 빌드되려면 이 플래그가 필요합니다.
# 더불어 PortAudio의 CMakeLists.txt에서 _WIN32 전처리기 매크로를 선언하였습니다.
set(WIN32 1)

add_subdirectory(lib/jansson)
add_subdirectory(lib/libfec)
add_subdirectory(lib/libsndfile)
add_subdirectory(lib/portaudio)
add_subdirectory(lib/quiet-dsp)
add_subdirectory(lib/libquiet)
add_subdirectory(lib/quiet-lwip)

add_executable(quiet_practice main.c)
target_link_libraries(quiet_practice quiet_lwip pthread)

add_executable(my_proxy_server proxy_server.c relay.c lwip.c util.c socks.c socks4.c socks5.c)
target_link_libraries(my_proxy_server quiet_lwip)

add_executable(my_proxy_client proxy_client.c relay.c lwip.c util.c)
target_link_libraries(my_proxy_client quiet_lwip)