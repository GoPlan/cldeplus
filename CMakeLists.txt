cmake_minimum_required(VERSION 3.2)
project(cloud_e_cplus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_cplus_SOURCE_DIR}/Build/bin")
set(SOURCE_FILES main.cpp)

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

add_library(apptest STATIC
    AppTest/StoreTest.h
    AppTest/StoreTest.cpp
)

add_executable(cloud_e_cplus ${SOURCE_FILES})

target_link_libraries(cloud_e_cplus architecture infrastructure application apptest)