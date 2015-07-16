cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(cldemysqldriver STATIC
    MySqlSourceDriver.h
    MySqlSourceDriver.cpp
    MySqlSourceException.h
    MySqlSourceException.cpp
MySqlSourceHelper.cpp MySqlSourceHelper.h Data/MySqlDate.cpp Data/MySqlDate.h Data/MySqlTime.cpp Data/MySqlTime.h Data/MySqlDateTime.cpp Data/MySqlDateTime.h)