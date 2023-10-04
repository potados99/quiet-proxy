cmake_minimum_required(VERSION 3.26)
project(quiet_practice C)

set(CMAKE_C_STANDARD 11)
set(WIN32 1)
set(_WIN32 1)

add_subdirectory(lib/jansson)
add_subdirectory(lib/libfec)
add_subdirectory(lib/libsndfile)
add_subdirectory(lib/portaudio)
add_subdirectory(lib/quiet-dsp)
add_subdirectory(lib/libquiet)
add_subdirectory(lib/quiet-lwip)

add_executable(quiet_practice main.c)
target_link_libraries(quiet_practice quiet_lwip pthread)

add_executable(my_proxy_server proxy_server.c relay.c)
target_link_libraries(my_proxy_server quiet_lwip)

add_executable(my_proxy_client proxy_client.c relay.c)
target_link_libraries(my_proxy_client quiet_lwip)