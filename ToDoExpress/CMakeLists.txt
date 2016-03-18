cmake_minimum_required(VERSION 2.8)

# Project-Name
PROJECT(tco_tool)

# C++ Compiler Definitions
add_definitions(-std=c++14)
add_definitions(-Wall)
add_definitions(-Wextra)
add_definitions(-Weffc++)


# Nana-Library Definitions
add_definitions(-DNANA_UNICODE)

# Boost-Definitions
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -DBOOST_NO_AUTO_PTR")

# set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../tco_tool_bin/")

# set debug & release version flags
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")

#add_subdirectory(unittests)

# set include direcoties
INCLUDE_DIRECTORIES(
                    ${CMAKE_CURRENT_SOURCE_DIR}/../nana/include
					C:/MinGW/include/
					${CMAKE_CURRENT_SOURCE_DIR}/../GSL/include/
					${CMAKE_CURRENT_SOURCE_DIR}/../json/src/
					)

# set link directories (where the libs are located)
LINK_DIRECTORIES(	${CMAKE_CURRENT_SOURCE_DIR}/extlib
					)

# set the files to compile
ADD_EXECUTABLE(tco_tool
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/application.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/controller.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/view.cpp
	                ${CMAKE_CURRENT_SOURCE_DIR}/src/core/modell.cpp
	                ${CMAKE_CURRENT_SOURCE_DIR}/src/core/project_loader.cpp
	                ${CMAKE_CURRENT_SOURCE_DIR}/src/simple_database.cpp
	                ${CMAKE_CURRENT_SOURCE_DIR}/src/nana_view.cpp
                )


# set libraries to link with
target_link_libraries(tco_tool
						libnana.a)
