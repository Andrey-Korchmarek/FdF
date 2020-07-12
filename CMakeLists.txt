cmake_minimum_required(VERSION 3.16.5)

project(FdF)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)

#FILE(GLOB LIBRARY libft21/*)
FILE(GLOB SOURCES ./srcs/*.c )

add_executable(FdF ${SOURCES} main.c )

add_subdirectory(libft)
add_subdirectory(minilibx_macos)
target_link_libraries(FdF lib minx)
