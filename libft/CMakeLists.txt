cmake_minimum_required(VERSION 3.16)
project(lib C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

file(GLOB SRCS *.c */*.c)
file(GLOB HEAD *.h)

add_library(lib STATIC ${SRCS} ${HEAD})
