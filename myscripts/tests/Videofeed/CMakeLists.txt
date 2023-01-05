cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(script)
add_executable(script test.cpp)
#[[ Set the path of opencv; Here I had to rename the cmake file due as OPENCVConfig.cmake from default OpenCVConfig.cmake]]
set(OPENCV_DIR "/usr/local/lib/cmake/opencv4")
find_package(OPENCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( script ${OpenCV_LIBS} )
