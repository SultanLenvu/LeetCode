cmake_minimum_required(VERSION 3.16)
project(CodeRun VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем цель сборки, исполняемый файл
add_executable(${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/main.cpp
    src/task7.hpp 
    src/task8.hpp 
    src/task9.hpp 
    src/task10.hpp 
    src/task17.hpp 
    src/task62.hpp 
    src/task74.hpp 
    src/task83.hpp
    src/task103.hpp 
    src/task130.hpp 
    src/task142.hpp 
)