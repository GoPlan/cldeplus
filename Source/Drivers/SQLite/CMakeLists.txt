cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(cldesqlitedriver STATIC
    SQLiteSourceDriver.cpp
    SQLiteSourceDriver.h
    SQLiteSourceException.cpp
    SQLiteSourceException.h
    SQLiteSourceHelper.cpp
    SQLiteSourceHelper.h
    Amalgamation/sqlite3.h
    Amalgamation/sqlite3ext.h
    Amalgamation/sqlite3.c
)