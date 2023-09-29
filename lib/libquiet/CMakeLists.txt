cmake_minimum_required (VERSION 2.6)
project (Quiet)
include(CheckLibraryExists)
include(CheckIncludeFiles)
include(CheckCCompilerFlag)

set(QUIET_PROFILES_LOCATION "${CMAKE_INSTALL_PREFIX}/share/quiet/")
add_definitions(-DQUIET_PROFILES_LOCATION="${QUIET_PROFILES_LOCATION}quiet-profiles.json")

if (CMAKE_C_COMPILER_ID MATCHES "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      add_definitions(-DQUIET_DEBUG)
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-no_pie")
  else()
      if(EMSCRIPTEN)
      elseif(CMAKE_C_COMPILER_ID MATCHES "Clang")
        check_c_compiler_flag("-Ofast" HAVE_O_FAST)
        if(HAVE_O_FAST)
          set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast -g3")
          set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Ofast -flto")
        else()
          set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g")
        endif()
      elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g")
      endif()
  endif()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpedantic -Wall -D_XOPEN_SOURCE=700 -std=c99")
endif()

set(CMAKE_MACOSX_RPATH 1)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

set(SRCFILES src/demodulator.c src/modulator.c src/utility.c src/decoder.c src/encoder.c src/profile.c src/error.c)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(CORE_DEPENDENCIES liquid-static jansson m)

set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads)
if (CMAKE_USE_PTHREADS_INIT)
  add_definitions(-DRING_BLOCKING=1)
  add_definitions(-DQUIET_PTHREAD_ERROR=1)
  set(SRCFILES ${SRCFILES} src/ring_blocking.c)
  set(CORE_DEPENDENCIES ${CORE_DEPENDENCIES} ${CMAKE_THREAD_LIBS_INIT})
else()
  add_definitions(-DRING_BLOCKING=0)
  add_definitions(-DQUIET_PTHREAD_ERROR=0)
  set(SRCFILES ${SRCFILES} src/ring.c)
endif()

# 라이브러리 찾지 않습니다. 모두 있는 것으로 간주합니다.
set(SRCFILES ${SRCFILES} src/portaudio_encoder.c src/portaudio_decoder.c)
add_definitions(-DQUIET_PORTAUDIO=1)
set(CORE_DEPENDENCIES ${CORE_DEPENDENCIES} portaudio_static)

add_library(quiet_static ${SRCFILES})
target_link_libraries(quiet_static ${CORE_DEPENDENCIES})
target_include_directories(quiet_static PUBLIC include)
set_target_properties(quiet_static PROPERTIES OUTPUT_NAME "quiet")
add_library(quiet SHARED ${SRCFILES})
target_link_libraries(quiet ${CORE_DEPENDENCIES})
set_target_properties(quiet PROPERTIES INSTALL_RPATH "@rpath/libquiet.dylib")

add_custom_target(lib DEPENDS quiet quiet_static)

add_custom_target(quiet-h ALL COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/include/quiet.h ${CMAKE_BINARY_DIR}/include/quiet.h)

add_custom_target(quiet-portaudio-h ALL COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/include/quiet-portaudio.h ${CMAKE_BINARY_DIR}/include/quiet-portaudio.h)

add_custom_target(quiet-profiles ALL COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/quiet-profiles.json ${CMAKE_BINARY_DIR}/share/quiet-profiles.json)

set(buildable_programs "")

add_executable(quiet_encode_file programs/encode_file.c)
target_link_libraries(quiet_encode_file quiet_static sndfile ${CMAKE_THREAD_LIBS_INIT})
set(buildable_programs ${buildable_programs} quiet_encode_file)

add_executable(quiet_decode_file programs/decode_file.c)
target_link_libraries(quiet_decode_file quiet_static sndfile ${CMAKE_THREAD_LIBS_INIT})
set(buildable_programs ${buildable_programs} quiet_decode_file)

add_executable(quiet_encode_soundcard programs/encode_soundcard.c)
target_link_libraries(quiet_encode_soundcard quiet_static ${CMAKE_THREAD_LIBS_INIT})
set(buildable_programs ${buildable_programs} quiet_encode_soundcard)

add_executable(quiet_decode_soundcard programs/decode_soundcard.c)
target_link_libraries(quiet_decode_soundcard quiet_static ${CMAKE_THREAD_LIBS_INIT})
set(buildable_programs ${buildable_programs} quiet_decode_soundcard)

add_custom_target(programs DEPENDS ${buildable_programs})

install(FILES ${CMAKE_BINARY_DIR}/share/quiet-profiles.json DESTINATION ${QUIET_PROFILES_LOCATION})
install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION include)
install(TARGETS ${buildable_programs}
                quiet quiet_static
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

add_custom_target(docs COMMAND cldoc generate -- --output docs/html --language=c ${CMAKE_BINARY_DIR}/include/quiet.h DEPENDS quiet-h)

add_executable(integration_test_runner EXCLUDE_FROM_ALL tests/integration.c)
target_link_libraries(integration_test_runner quiet_static)
set_target_properties(integration_test_runner PROPERTIES RUNTIME_OUTPUT_DIRECTORY "tests")
add_test(NAME integration_test WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tests" COMMAND integration_test_runner)

add_custom_target(test-profiles COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/tests/test-profiles.json ${CMAKE_BINARY_DIR}/tests/test-profiles.json)
add_custom_target(cp-test-profiles DEPENDS test-profiles)
add_dependencies(integration_test_runner cp-test-profiles)

set(TEST_RUNNERS integration_test_runner)

if (CMAKE_USE_PTHREADS_INIT)
  add_executable(test_ring_blocking EXCLUDE_FROM_ALL tests/ring_blocking.c src/ring_blocking.c)
  target_link_libraries(test_ring_blocking ${CMAKE_THREAD_LIBS_INIT})
  set_target_properties(test_ring_blocking PROPERTIES RUNTIME_OUTPUT_DIRECTORY "tests")
  add_test(NAME ring_blocking_test WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tests" COMMAND test_ring_blocking)
  set(TEST_RUNNERS ${TEST_RUNNERS} test_ring_blocking)
endif()

add_custom_target(test_runners DEPENDS ${TEST_RUNNERS})
add_custom_target(libquiet_check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS test_runners)
enable_testing()
