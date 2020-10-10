
cmake_minimum_required(VERSION 2.8)

#set(CMAKE_BUILD_TYPE "Debug")
project(sg3_utils_project)

add_definitions(-D _CRT_SECURE_NO_WARNINGS)

add_subdirectory(lib)
add_subdirectory(demo)
