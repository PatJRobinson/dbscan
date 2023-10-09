cmake_minimum_required(VERSION 3.0)

project(dbscan)

add_executable(${PROJECT_NAME} dbscan.cpp example.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE vendor)