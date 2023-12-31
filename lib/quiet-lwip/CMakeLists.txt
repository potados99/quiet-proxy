cmake_minimum_required (VERSION 2.6)
project (Quiet-LWIP)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DQUIET_DEBUG)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3 -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
else()
    if("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Ofast -flto")
    else()
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
    endif()
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wpedantic -Wall")
if (NOT APPLE)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE=700")
endif()
set(SRCFILES src/driver.c src/util.c)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include/lwip)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include/lwip/ipv4)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_subdirectory(src/lwip)

set(CORE_DEPENDENCIES quiet_static pthread)

set(SRCFILES ${SRCFILES} src/driver_portaudio.c)
add_definitions(-DQUIET_PORTAUDIO=1)
set(CORE_DEPENDENCIES ${CORE_DEPENDENCIES} portaudio_static)
add_custom_target(quiet-lwip-portaudio-h ALL COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/include/quiet-lwip-portaudio.h ${CMAKE_BINARY_DIR}/include/quiet-lwip-portaudio.h)

add_library(quiet_lwip STATIC ${SRCFILES} $<TARGET_OBJECTS:lwip_sys> $<TARGET_OBJECTS:lwip_core> $<TARGET_OBJECTS:lwip_api> $<TARGET_OBJECTS:lwip_netif> $<TARGET_OBJECTS:lwip_ipv4>)
target_include_directories(quiet_lwip PUBLIC
        include
        include/lwip
        include/lwip/ipv4
)
target_link_libraries(quiet_lwip ${CORE_DEPENDENCIES})

add_custom_target(lwip-h ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/include/lwip/ ${CMAKE_BINARY_DIR}/include/lwip)
add_custom_target(quiet-lwip-h ALL COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/include/quiet-lwip.h ${CMAKE_BINARY_DIR}/include/quiet-lwip.h)

add_subdirectory(examples)
