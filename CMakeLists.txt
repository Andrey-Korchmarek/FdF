cmake_minimum_required(VERSION 3.16.5)

project(FdF)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)

FILE(GLOB LIBRARY libft/*.c)
FILE(GLOB LIBHEAD libft/*.h)
FILE(GLOB MLX minilibx_macos/*.c)
FILE(GLOB MLXHEAD minilibx_macos/*.h)
FILE(GLOB SOURCES ./srcs/*.c )

add_executable(FdF ${SOURCES} main.c ${LIBRARY} ${LIBHEAD} ${MLX} ${MLXHEAD})

#add_subdirectory(libft)
#add_subdirectory(minilibx_macos)
#target_link_libraries(FdF lib mlx "-framework OpenGL" "-framework AppKit")

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIR})
target_link_libraries(FdF ${OpenGL_LIBRARIES})

#target_link_libraries(FdF
#        lib mlx "-framework OpenGL" "-framework AppKit")