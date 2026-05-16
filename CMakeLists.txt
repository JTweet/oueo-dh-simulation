cmake_minimum_required(VERSION 4.3.2)

project(DhTest, LANGUAGES CXX)

set(CMAKE_OSX_ARCHITECTURES "arm64"
    CACHE STRING "The list of target architectures to build")

include(FetchContent)

add_subdirectory(libsrc)
add_subdirectory(src)