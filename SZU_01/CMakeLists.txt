cmake_minimum_required(VERSION 3.8)
project(SZU_01)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES source/HaarDetection.cpp header/HaarDetection.h source/Read.cpp header/Read.h source/main.cpp header/TurnImg.h source/TurnImg.cpp header/EdgeSobel.h source/EdgeSobel.cpp)
add_executable(SZU_01 ${SOURCE_FILES})

target_link_libraries(SZU_01 ${OpenCV_LIBS})