cmake_minimum_required(VERSION 3.26)
project(quiet_practice C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/jansson)
add_subdirectory(lib/libfec)
add_subdirectory(lib/portaudio)
add_subdirectory(lib/quiet-dsp)
add_subdirectory(lib/libquiet)
add_subdirectory(lib/quiet-lwip)

set(server_src proxy_server.c relay.c util.c socks.c socks4.c socks5.c)
set(client_src proxy_client.c relay.c util.c)

add_executable(proxy_server_lwip ${server_src} lwip.c)
target_link_libraries(proxy_server_lwip quiet_lwip)

add_executable(proxy_client_lwip ${client_src} lwip.c)
target_link_libraries(proxy_client_lwip quiet_lwip)

add_custom_target(proxy_lwip DEPENDS proxy_server_lwip proxy_client_lwip)

add_executable(proxy_server_native ${server_src})
target_compile_definitions(proxy_server_native PRIVATE LOCAL_TEST)

add_executable(proxy_client_native ${client_src})
target_compile_definitions(proxy_client_native PRIVATE LOCAL_TEST)

add_custom_target(proxy_native DEPENDS proxy_server_native proxy_client_native)
