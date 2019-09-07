cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(task_3_1 LANGUAGES CXX)
add_executable(${PROJECT_NAME} main.cpp task_3_1.hpp )
target_compile_features(${PROJECT_NAME}
    PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_EXTENSIONS OFF)
