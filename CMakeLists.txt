cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_SOURCE_DIR "Source")

# INCLUDE directories
include_directories(Extra/libs/cldeparser/include)
include_directories(Extra/libs/mysql-connector-c-6.1.6-osx10.8-x86_64/include)
include_directories(Extra/libs/gtest-1.7.0/include)
# include_directories(/opt/local/include/postgresql94)
# include_directories(/usr/local/include/libbson-1.0)
# include_directories(/usr/local/include/libmongoc-1.0)

# LIBRARIES directories
LINK_DIRECTORIES(Extra/libs/cldeparser)
LINK_DIRECTORIES(Extra/libs/mysql-connector-c-6.1.6-osx10.8-x86_64/lib)
LINK_DIRECTORIES(Extra/libs/gtest-1.7.0/lib)
# LINK_DIRECTORIES(/opt/local/lib/postgresql94)

# TARGET-LIBRARIES (Sub-directories)
add_subdirectory(Source/Foundation)
add_subdirectory(Source/Relation)
add_subdirectory(Source/Segmentation)
add_subdirectory(Source/Drivers/SQLite)
add_subdirectory(Source/Drivers/MySql)
add_subdirectory(Source/Configuration)
add_subdirectory(Examples)
add_subdirectory(Test)

# TARGET-EXECUTABLE: cloud_e_plus
add_executable(cloud_e_plus_test Test/main.cpp)
target_link_libraries(cloud_e_plus_test foundation segmentation relation configuration)
target_link_libraries(cloud_e_plus_test application apptest gtest)
target_link_libraries(cloud_e_plus_test cldesqlitedriver cldemysqldriver)
target_link_libraries(cloud_e_plus_test mysqlclient)
#target_link_libraries(cloud_e_plus_test pq)
#target_link_libraries(cloud_e_plus_test mongoc-1.0 bson-1.0)

# TEST
#enable_testing()
#add_test(cloud_e_plus_test cloud_e_plus_test)
