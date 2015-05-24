cmake_minimum_required(VERSION 3.2)
project(cloud_e_cplus)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_cplus_SOURCE_DIR}/Build/bin")
set(SOURCE_FILES main.cpp)


include_directories(${CMAKE_SOURCE_DIR})


add_library(architecture STATIC
    Architecture/Enumeration/DbType.h
    Architecture/Identity.cpp
    Architecture/Identity.h
    Architecture/Column.cpp
    Architecture/Column.h
    Architecture/Field.cpp
    Architecture/Field.h
    Architecture/Entity.cpp
    Architecture/Entity.h
    Architecture/EntityStore.cpp
    Architecture/EntityStore.h
    Architecture/EntityMap.cpp
    Architecture/EntityMap.h
    Architecture/EntityLoader.cpp
    Architecture/EntityLoader.h
    Cloude.h
)


add_library(application STATIC
    Application/Model/Account.cpp
    Application/Model/Account.h
    Application/Model/StockGroup.cpp
    Application/Model/StockGroup.h
    Application/Mapper/StockGroupMap.cpp
    Application/Mapper/StockGroupMap.h
    Application/Mapper/StockGroupLoader.cpp
    Application/Mapper/StockGroupLoader.h
)


add_library(infrastructure STATIC
    Infrastructure/Driver/MySqlDriver.h
    Infrastructure/Driver/MySqlDriver.cpp
)


add_library(examples STATIC
    Examples/mysql_c_example.h
    Examples/mysql_c_example.cpp
    Examples/main.cpp
)


add_library(apptest STATIC
    AppTest/Store/StoreSimple.cpp
    AppTest/Store/StoreSimple.h
    AppTest/Store/CreateTest.h
    AppTest/main.cpp
)


# Libs
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/Libs)


# MySql Client
set(MYSQL_DIR ${LIBS_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64)
include_directories(${MYSQL_DIR}/include)
LINK_DIRECTORIES(${MYSQL_DIR}/lib)


# Examples
set(EXAMPLES_DIR ${CMAKE_SOURCE_DIR}/Examples)
set(EXAMPLES_SOURCE_FILE ${EXAMPLES_DIR}/main.cpp)


# Examples Target
add_executable(cloud_e_cplus_example ${EXAMPLES_SOURCE_FILE})
target_link_libraries(cloud_e_cplus_example mysqlclient examples)


# Sandbox Target
add_executable(cloud_e_cplus_debug ${SOURCE_FILES})
target_link_libraries(cloud_e_cplus_debug architecture infrastructure application mysqlclient examples)


# AppTest Target (with Google Testing Framework)
set(GTEST_LIB_DIR ${LIBS_DIR}/gtest-1.7.0)
set(APPTEST_SOURCE_FILE ${CMAKE_SOURCE_DIR}/AppTest/main.cpp)
include_directories(${GTEST_LIB_DIR}/include)
LINK_DIRECTORIES(${GTEST_LIB_DIR}/lib)

add_executable(cloud_e_cplus_test ${APPTEST_SOURCE_FILE})
target_link_libraries(cloud_e_cplus_test architecture infrastructure application apptest gtest)