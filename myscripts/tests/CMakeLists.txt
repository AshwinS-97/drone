cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(script)
add_executable(script script.cpp)
find_package(MAVSDK REQUIRED)
target_link_libraries(script MAVSDK::mavsdk)