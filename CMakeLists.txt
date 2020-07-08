cmake_minimum_required(VERSION 3.16.5)

project(FdF)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)

FILE(GLOB LIBRARY ./libft/* )
FILE(GLOB SOURCES ./srcs/*.c )

#add_subdirectory(libft)

add_executable(FdF ${LIBRARY} ${SOURCES} main.c )