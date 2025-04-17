cmake_minimum_required(VERSION 3.10)

project(GMAIL)

set(CMAKE_CXX_STANDARD 11)
# Collect all .cpp files from current directory
file(GLOB CURRENT_SOURCES "*.cpp")

add_executable(Gmail main.cpp ${CURRENT_SOURCES})