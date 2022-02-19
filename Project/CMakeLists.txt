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

option(BUILD_SHARED_LIBS "Generated shared objects instead of archives" TRUE)

include_directories(
    "${CMAKE_SOURCE_DIR}/include"
)

add_library("${CMAKE_PROJECT_NAME}")

add_subdirectory("src")