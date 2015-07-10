cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_plus_SOURCE_DIR}/.local/build/bin")

# INCLUDE directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/.local/libs/boost_1_58_0)
include_directories(${CMAKE_SOURCE_DIR}/.local/libs/mysql-connector-c-6.1.6-osx10.8-x86_64/include)
include_directories(/opt/local/include/postgresql94)
include_directories(/usr/local/include/libbson-1.0)
include_directories(/usr/local/include/libmongoc-1.0)
include_directories(AppTest/.local/gtest-1.7.0/include)

# LIBRARIES directories
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/.local/libs/mysql-connector-c-6.1.6-osx10.8-x86_64/lib)
LINK_DIRECTORIES(/opt/local/lib/postgresql94)
LINK_DIRECTORIES(AppTest/.local/gtest-1.7.0/lib)

# TARGET-LIBRARIES (Sub-directories)
add_subdirectory(Foundation)
add_subdirectory(Booting)
add_subdirectory(Drivers/SQLite)
add_subdirectory(Relation)
add_subdirectory(Segmentation)
add_subdirectory(AppTest)
add_subdirectory(.examples)

# TARGET-EXECUTABLE: debug
add_executable(cloud_e_plus_debug main.cpp)

# TARGET-EXECUTABLE: cloud_e_plus
add_executable(cloud_e_plus_test AppTest/main.cpp)
target_link_libraries(cloud_e_plus_test foundation segmentation relation booting)
target_link_libraries(cloud_e_plus_test application apptest gtest)
target_link_libraries(cloud_e_plus_test cldesqlitedriver)
#target_link_libraries(cloud_e_plus_test mysqlclient pq mongoc-1.0 bson-1.0)