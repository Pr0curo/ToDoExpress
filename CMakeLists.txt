cmake_minimum_required(VERSION 3.4)
project(ToDoExpress)

# C++ Compiler Definitions
add_definitions(-std=c++14)

set(SOURCE_FILES
	ToDoExpress/source/main.cpp)

include_directories(ToDoExpress/include)
include_directories(ToDoLibrary/include)

add_executable(ToDoExpress ${SOURCE_FILES})