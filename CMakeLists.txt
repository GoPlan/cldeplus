cmake_minimum_required(VERSION 3.2)
project(cloud_e_cplus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cloud_e_cplus ${SOURCE_FILES} Architecture/Foundation/Identity.cpp Architecture/Foundation/Identity.h Architecture/Foundation/Column.cpp Architecture/Foundation/Column.h Architecture/Foundation/Field.cpp Architecture/Foundation/Field.h Architecture/Foundation/Entity.cpp Architecture/Foundation/Entity.h Architecture/Enumeration/DbType.h Architecture/Contract/HasIdentity.h Architecture/Foundation/EntityStore.cpp Architecture/Foundation/EntityStore.h)