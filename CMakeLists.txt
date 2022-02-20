cmake_minimum_required(VERSION "3.13")

project("scp-game-framework")

option(BUILD_SHARED_LIBS "Generate shared libraries instead of static object archives." TRUE)
option(SCP_BUILD_TESTS "Generate the test files." FALSE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
endif()
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_BUILD_RPATH "$ORIGIN:$ORIGIN/../lib")
set(CMAKE_INSTALL_RPATH "$ORIGIN:$ORIGIN/../lib")

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options("-fdiagnostics-absolute-paths")
endif()

if (BUILD_SHARED_LIBS AND WIN32)
    add_compile_definitions("SCP_DLL")
endif()

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library("scp-game-framework")

if (BUILD_SHARED_LIBS AND WIN32)
    target_compile_definitions("scp-game-framework" PRIVATE "SCP_BUILD_DLL")
endif()

add_subdirectory("src")

if (SCP_BUILD_TESTS)
    add_subdirectory("tests")
endif()