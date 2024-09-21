cmake_minimum_required(VERSION 3.29)
project(YasRenderer)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

find_package(SDL2 REQUIRED)

add_executable(YasRenderer main.cpp
        renderer.cpp
        renderer.hpp
        pixels_table.cpp
        pixels_table.hpp
        vector_2d.hpp
        vector_4d.hpp
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})