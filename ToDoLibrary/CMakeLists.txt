cmake_minimum_required(VERSION 3.3)

# Project-Name
PROJECT(ToDoLibrary)


# C++ Compiler Definitions
add_definitions(-std=c++14)
add_definitions(-Wall)
add_definitions(-Wextra)
#add_definitions(-Weffc++)

# set debug & release version flags
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")


# set include direcoties
INCLUDE_DIRECTORIES(C:/MinGW/include/
					${CMAKE_CURRENT_SOURCE_DIR}/../../GSL/include/
					${CMAKE_CURRENT_SOURCE_DIR}/../../json/src/
					${CMAKE_CURRENT_SOURCE_DIR}/include/
					)

# set the files to compile
ADD_LIBRARY(ToDoLibrary
                    ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/source/todo_list.cpp
                    )

add_subdirectory(unittests)

add_custom_target( run_test ALL
                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/unittests/ToDoLibraryTests
                   COMMENT UnitTests:
                   DEPENDS ToDoLibrary ToDoLibraryTests # depends on the library and Tests, so it gets called last
                   )