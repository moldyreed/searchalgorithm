cmake_minimum_required(VERSION 2.8)
project(searchalgorithm CXX)


set(CMAKE_BUILD_TYPE "Debug")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/build/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/build/lib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-deprecated")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g3")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3")

INCLUDE_DIRECTORIES(
	src/${PROJECT_NAME}/
)

add_executable(
	${PROJECT_NAME}
	
	src/main.cpp
        src/boyermoorehorspoolsearch.cpp
        src/searchresults.cpp
)

install(TARGETS ${PROJECT_NAME} DESTINATION "bin")
