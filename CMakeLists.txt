cmake_minimum_required(VERSION 3.5)

project(dbscan)

add_library(${PROJECT_NAME} dbscan.cpp example.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE vendor)
target_include_directories(${PROJECT_NAME} PUBLIC include)
