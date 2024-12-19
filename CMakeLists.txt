cmake_minimum_required(VERSION 3.5)

project(dbscan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME} example.cpp dbscan.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor ${CMAKE_CURRENT_BINARY_DIR_SOURCE_DIR})