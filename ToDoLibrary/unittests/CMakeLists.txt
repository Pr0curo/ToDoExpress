cmake_minimum_required(VERSION 2.8)

# Project-Name
PROJECT(ToDoLibraryTests)

# C++ Compiler Definitions
add_definitions(-std=c++14)
add_definitions(-Wall)
add_definitions(-Wextra)

IF(MINGW)
	set(gtest_disable_pthreads ON)
ENDIF()

add_subdirectory(googletest/googletest)

# set include direcoties
INCLUDE_DIRECTORIES(C:/MinGW/include/
                    ${CMAKE_CURRENT_SOURCE_DIR}/../src/
                    ${CMAKE_CURRENT_SOURCE_DIR}/../include/
					)

# set the files to compile
ADD_EXECUTABLE(ToDoLibraryTests
                    ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
                )


# set libraries to link with
target_link_libraries(ToDoLibraryTests ToDoLibrary gtest gtest_main)
