cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

# Build variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Directories
set(EXTRA_DIR "${CMAKE_SOURCE_DIR}/Extra")
set(GTEST "${EXTRA_DIR}/gtest-1.7.0")
set(CLDEPARSER "${EXTRA_DIR}/cldeparser-0.9.0")


# TARGET-LIBRARIES (Sub-directories)
add_subdirectory(Source/Foundation)
add_subdirectory(Source/Relation)
add_subdirectory(Source/Segmentation)
add_subdirectory(Source/Drivers/SQLite)
add_subdirectory(Source/Drivers/MySql)
add_subdirectory(Source/Configuration)
add_subdirectory(Examples)
add_subdirectory(Test)


# TEST
#enable_testing()
#add_test(cloud_e_plus_test cloud_e_plus_test)
