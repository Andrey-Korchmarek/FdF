cmake_minimum_required(VERSION 3.5.1)
project(libft C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(.)

file(GLOB SRCS "*.c")
file(GLOB HEAD *.h)

add_library(lib STATIC ${SRCS} ${HEAD})