cmake_minimum_required(VERSION 2.8)

# PROJECT SETUP #
project(SQE_CourseProject)

#set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 11)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

# Source files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
# Main -- separate executable
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)
# Compile source files into a library
add_library(SQE_CourseProject_lib ${SRC_FILES})
add_executable(SQE_CourseProject ${PROJECT_SOURCE_DIR}/src/main.cpp)
# linking Main against the library
target_link_libraries(SQE_CourseProject SQE_CourseProject_lib)

# TESTSING #
add_subdirectory(gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Test files
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
# Unit Tests
add_executable(runUnitTests ${TEST_SRC_FILES})

# Standard linking to gtest stuff
target_link_libraries(runUnitTests gtest gtest_main)
# Extra linking for the project
target_link_libraries(runUnitTests SQE_CourseProject_lib)

add_test(UnitTests runUnitTests)