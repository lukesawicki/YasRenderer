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
        yas_application.cpp
        yas_application.hpp
        time_picker.cpp
        time_picker.hpp
        vector_3d.hpp
        point_3d.hpp
        line_3d.hpp
        polygon_2d.hpp
        matrix_1_2.hpp
        matrix_1_3.hpp
        matrix_1_4.hpp
        matrix_2_2.hpp
        matrix_3_2.hpp
        matrix_3_3.hpp
        matrix_4_3.hpp
        matrix_4_4.hpp
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})