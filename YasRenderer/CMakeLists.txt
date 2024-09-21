cmake_minimum_required(VERSION 3.29)
project(YasRenderer)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

find_package(SDL2 REQUIRED)

add_executable(YasRenderer main.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})