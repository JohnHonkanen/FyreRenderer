cmake_minimum_required(VERSION 3.13)
project(Renderer)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set (LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)



add_subdirectory(${LIB_DIR}/glfw-3.3.1)

add_library(Renderer SHARED ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/src/glad.c Renderer/Core/window.cpp Renderer/Core/window.h Renderer/Core/FyreRenderer.cpp Renderer/Core/FyreRenderer.h)

include_directories(Renderer ${LIB_DIR}/glad/include)

add_executable(Demo main.cpp)

find_package(OpenGL REQUIRED)

target_link_libraries(Renderer glfw OpenGL::GL)


target_link_libraries(Demo Renderer)

