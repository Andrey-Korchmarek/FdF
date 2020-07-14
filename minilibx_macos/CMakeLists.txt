cmake_minimum_required(VERSION 3.16)
project(minilibx_macos C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

file(GLOB SRCS "*.c" *.m font.xcf)
file(GLOB HEAD *.h)

add_library(mlx STATIC ${SRCS} ${HEAD})