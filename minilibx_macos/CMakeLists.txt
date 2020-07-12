cmake_minimum_required(VERSION 3.16)
project(minix)

set(CMAKE_C_STANDARD 11)

file(GLOB SRCS "*.c")
file(GLOB HEAD *.h)

add_library(minix ${SRCS} ${HEAD})
target_include_directories(mlx PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#find_package(OpenGL REQUIRED)
#include_directories(${OpenGL_INCLUDE_DIR})
target_link_libraries(mlx ${OpenGL_LIBRARIES})