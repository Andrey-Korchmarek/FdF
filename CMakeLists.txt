cmake_minimum_required(VERSION 3.16)
project(FdF)

set(CMAKE_CXX_STANDARD 11)

include_directories(./srcs)
FILE(GLOB SOURCES ./srcs/*.c )

add_executable(FdF ${SOURCES} srcs/get_z_matrix.c main.c fdf.h)

add_subdirectory(libft)
target_link_libraries(FdF lib)

add_library(mlx STATIC IMPORTED)
set_property(TARGET mlx PROPERTY
        IMPORTED_LOCATION ./minilibx_macos/libmlx.a)
target_link_libraries(${TARGET} mlx)