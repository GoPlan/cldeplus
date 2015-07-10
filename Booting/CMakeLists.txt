cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

add_library(booting STATIC
    Registry.cpp
    Registry.h
    Exception/RegistryException.cpp
    Exception/RegistryException.h
    )