cmake_minimum_required(VERSION 3.16)
project(FdF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -Wextra")
set(LIBMLX ${CMAKE_SOURCE_DIR}/minilibx_macos/libmlx.a)

find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)

include_directories(./srcs)
FILE(GLOB SOURCES ./srcs/*.c )

add_executable(FdF ${SOURCES} main.c fdf.h )

add_subdirectory(libft)
#target_link_libraries(FdF lib  ${LIBMLX} ${OPENGL} ${APPKIT})

add_library(mlx STATIC IMPORTED)
set_property(TARGET mlx PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/minilibx_macos/libmlx.a)
target_link_libraries(FdF lib mlx ${OPENGL} ${APPKIT})