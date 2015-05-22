cmake_minimum_required(VERSION 3.2)
project(cloud_e_cplus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_cplus_SOURCE_DIR}/Build/bin")
set(SOURCE_FILES main.cpp)

include_directories(${CMAKE_SOURCE_DIR})

add_library(architecture STATIC
    Architecture/Enumeration/DbType.h
    Architecture/Contract/HasIdentity.h
    Architecture/Foundation/Identity.cpp
    Architecture/Foundation/Identity.h
    Architecture/Foundation/Column.cpp
    Architecture/Foundation/Column.h
    Architecture/Foundation/Field.cpp
    Architecture/Foundation/Field.h
    Architecture/Foundation/Entity.cpp
    Architecture/Foundation/Entity.h
    Architecture/Foundation/EntityStore.cpp
    Architecture/Foundation/EntityStore.h
    Architecture/Foundation/EntityMap.cpp
    Architecture/Foundation/EntityMap.h
    Architecture/Foundation/EntityQuery.cpp
    Architecture/Foundation/EntityQuery.h
    Architecture/Foundation/Proxy.cpp
    Architecture/Foundation/Proxy.h
    Architecture/Foundation/EntityLoader.cpp
    Architecture/Foundation/EntityLoader.h
    Architecture/Cloude.h
    Architecture/Foundation/TransactionUnit.cpp
    Architecture/Foundation/TransactionUnit.h
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


# Sandbox Target
add_executable(cloud_e_cplus ${SOURCE_FILES})
target_link_libraries(cloud_e_cplus architecture infrastructure application mysqlclient examples)

# AppTest Target (with Google Testing Framework)
set(GTEST_LIB_DIR ${LIBS_DIR}/gtest-1.7.0)
set(APPTEST_SOURCE_FILE ${CMAKE_SOURCE_DIR}/AppTest/main.cpp)
include_directories(${GTEST_LIB_DIR}/include)
LINK_DIRECTORIES(${GTEST_LIB_DIR}/lib)

add_executable(cloud_e_cplus_test ${APPTEST_SOURCE_FILE})
target_link_libraries(cloud_e_cplus_test architecture infrastructure application apptest gtest)