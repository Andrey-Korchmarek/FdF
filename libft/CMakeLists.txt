cmake_minimum_required(VERSION 3.5.1)
project(libft C)

set(CMAKE_C_STANDARD 99)

include_directories(.)
#include_directories(./array_int)
#include_directories(./ft_printf)

file(GLOB SRCS "*.c" "./*/*.c")
file(GLOB HEAD *.h ./*/*.h)

add_library(lib STATIC ${SRCS} ${HEAD})