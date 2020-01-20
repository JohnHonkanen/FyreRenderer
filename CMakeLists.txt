cmake_minimum_required(VERSION 3.13)
project(Renderer)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw-3.3.1/include)

add_library(Renderer SHARED library.cpp library.h)

target_link_libraries(Renderer ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw-3.3.1/libs/win32/glfw3.lib)

add_executable(Demo main.cpp)
link_libraries(Demo Renderer)

