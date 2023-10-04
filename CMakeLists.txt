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

# 데몬: 테스트용으로 Winsock을 사용하는 버전
add_executable(tunnel_daemon_winsock tunnel_daemon.c
        transport_winsock.c
        array_list.c
        connection.c
        handshake_winsock.c
        handshake_lwip.c)
target_link_libraries(tunnel_daemon_winsock pthread wsock32 ws2_32)
target_compile_definitions(tunnel_daemon_winsock PRIVATE USE_WINSOCK)

# 데몬: 배포용으로 lwip를 사용하는 버전
add_executable(tunnel_daemon_lwip tunnel_daemon.c
        transport_lwip.c
        array_list.c
        connection.c
        handshake_winsock.c
        handshake_lwip.c)
target_link_libraries(tunnel_daemon_lwip quiet_lwip wsock32 ws2_32)
target_compile_definitions(tunnel_daemon_lwip PRIVATE _LWIP_DO_NOT_DEFINE_BSD_TYPES)

# 클라이언트
add_executable(tunnel_client tunnel_client.c
        handshake_winsock.c)
target_link_libraries(tunnel_client pthread wsock32 ws2_32)
