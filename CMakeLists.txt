cmake_minimum_required(VERSION 3.26)
project(quiet_practice C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/jansson)
add_subdirectory(lib/libfec)
add_subdirectory(lib/libsndfile)
add_subdirectory(lib/portaudio)
add_subdirectory(lib/quiet-dsp)
add_subdirectory(lib/libquiet)
add_subdirectory(lib/quiet-lwip)

add_executable(quiet_practice main.c)
target_link_libraries(quiet_practice jansson fec sndfile portaudio_static liquid-static quiet_static quiet_lwip)

add_executable(my_kv_client examples/kv_client.c)
target_link_libraries(my_kv_client quiet_lwip)

add_executable(my_kv_server examples/kv_server.c)
target_link_libraries(my_kv_server quiet_lwip)

add_executable(my_send examples/send.c)
target_link_libraries(my_send quiet_lwip)

add_executable(my_receive examples/receive.c)
target_link_libraries(my_receive quiet_lwip)

# 테스트용으로 Winsock을 사용하는 버전
add_executable(practice_winsock main.c transport_winsock.c)
target_link_libraries(practice_winsock pthread wsock32 ws2_32)
target_compile_definitions(practice_winsock PRIVATE USE_WINSOCK)

# 배포용으로 lwip를 사용하는 버전
add_executable(practice_lwip main.c transport_lwip.c)
target_link_libraries(practice_lwip quiet_lwip)
