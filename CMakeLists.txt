cmake_minimum_required(VERSION 3.8)
project(LibMathUnitTest)
set (CMAKE_CXX_STANDARD 17)

set(SOURCES
    
    "Sources/main.cpp"
    "Externals/LibMath/Maths.cpp")

include_directories ("Externals")

add_executable (${PROJECT_NAME} ${SOURCES})