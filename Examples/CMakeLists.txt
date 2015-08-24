cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(examples STATIC
    main.cpp
    mysql_c_example.h
    mysql_c_example.cpp
    mongodb_c_example.cpp
    mongodb_c_example.h
)

# TARGET: examples
set(EXAMPLES_DIR ${CMAKE_SOURCE_DIR}/Examples)
set(EXAMPLES_SOURCE_FILE ${EXAMPLES_DIR}/main.cpp)
add_executable(cloud_e_plus_example ${EXAMPLES_SOURCE_FILE})
target_link_libraries(cloud_e_plus_example examples mysqlclient mongoc-1.0 bson-1.0)