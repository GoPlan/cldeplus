cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(cldemysqldriver STATIC
    MySqlSourceDriver.h
    MySqlSourceDriver.cpp
    MySqlSourceException.h
    MySqlSourceException.cpp
)