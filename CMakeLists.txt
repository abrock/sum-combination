cmake_minimum_required(VERSION 3.5)

project(sum-combination LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sum-combination main.cpp)

add_library(sumcombination sumcombination.cpp)

target_link_libraries(sum-combination sumcombination)
