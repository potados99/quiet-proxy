cmake_minimum_required(VERSION 3.26)
project(quiet_practice C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/jansson)
add_subdirectory(lib/libfec)
add_subdirectory(lib/libsndfile)

add_executable(quiet_practice main.c)
target_link_libraries(quiet_practice jansson fec sndfile)
