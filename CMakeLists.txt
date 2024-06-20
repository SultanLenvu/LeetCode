cmake_minimum_required(VERSION 3.16)
project(LeetCode VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем цель сборки, исполняемый файл
add_executable(${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/main.cpp
    src/dfs.hpp src/dfs.cpp
)