cmake_minimum_required(VERSION "3.13")

project("scp-game-framework")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Application/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Application/lib")
set(CMAKE_BUILD_RPATH "$ORIGIN:$ORIGIN/../lib")
set(CMAKE_INSTALL_RPATH "$ORIGIN:$ORIGIN/../lib")

# Windows specific variables
if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Application/bin")
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../Application/lib")
endif()

# Operating system defines (more reliable than ones created by the compiler)
if (WIN32)
    add_compile_definitions("SCP_PLATFORM_WINDOWS")
elseif(UNIX AND NOT APPLE)
    add_compile_definitions("SCP_PLATFORM_LINUX")
elseif(APPLE)
    add_compile_definitions("SCP_PLATFORM_MAC")
endif()

# Clang specific options
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options("-Wall" "-Wextra" "-Werror" "-fdiagnostics-absolute-paths")
    add_link_options("-fdiagnostics-absolute-paths")
endif()

option(BUILD_SHARED_LIBS "Generated shared objects instead of archives" TRUE)

include_directories(
    "${CMAKE_SOURCE_DIR}/include"
)

add_library("${CMAKE_PROJECT_NAME}")

# If we are creating a Windows DLL, make sure to define the macros for exporti-
# ng sybmols
if (WIN32 AND BUILD_SHARED_LIBS)
    add_compile_definitions("SCP_DLL")
    target_compile_definitions("SCP_BUILD_DLL")
endif()

add_subdirectory("src")