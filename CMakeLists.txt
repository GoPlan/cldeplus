cmake_minimum_required(VERSION 3.2)
project(cloud_e_cplus)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -std=gnu++0x")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_cplus_SOURCE_DIR}/Build/bin")
set(SOURCE_FILES main.cpp)


include_directories(${CMAKE_SOURCE_DIR})


add_library(architecture STATIC
    Cloude.h
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
    Architecture/Exception/NonSupportedDataTypeException.cpp
    Architecture/Exception/NonSupportedDataTypeException.h
    Architecture/Exception/DataSourceRoutineException.cpp
    Architecture/Exception/DataSourceRoutineException.h
    Architecture/Exception/EntityStoreRoutineException.cpp
    Architecture/Exception/EntityStoreRoutineException.h
    Architecture/Helper/SqlGenerator.cpp
    Architecture/Helper/SqlGenerator.h
    Architecture/Exception/EntityException.cpp
    Architecture/Exception/EntityException.h
    Architecture/DataSource/Command.cpp
    Architecture/DataSource/Command.h
    Architecture/DataSource/Connector.h
    Architecture/DataSource/Connector.cpp
    Architecture/EntitySourceDriver.cpp
    Architecture/EntitySourceDriver.h
    Architecture/Helper/EntityStoreHelper.cpp
    Architecture/Helper/EntityStoreHelper.h)


add_library(application STATIC
    Application/Model/Account.cpp
    Application/Model/Account.h
    Application/Model/StockGroup.cpp
    Application/Model/StockGroup.h
    Application/Mapper/StockGroupMap.cpp
    Application/Mapper/StockGroupMap.h
    Application/Mapper/StockGroupLoader.cpp
    Application/Mapper/StockGroupLoader.h
    Application/Model/Sequence.cpp
    Application/Model/Sequence.h
    Application/Mapper/AccountMap.cpp
    Application/Mapper/AccountMap.h
    Application/Mapper/SequenceMap.cpp
    Application/Mapper/SequenceMap.h
    Application/Mapper/SequenceLoader.cpp
    Application/Mapper/SequenceLoader.h Application/Model/Enquiry.cpp Application/Model/Enquiry.h Application/Mapper/EnquiryMap.cpp Application/Mapper/EnquiryMap.h Application/Mapper/EnquiryLoader.cpp Application/Mapper/EnquiryLoader.h)


add_library(infrastructure STATIC
    Infrastructure/MySql/MySqlSourceDriver.h
    Infrastructure/MySql/MySqlSourceDriver.cpp
    Infrastructure/Postgres/PostgreSourceDriver.cpp
    Infrastructure/Postgres/PostgreSourceDriver.h
    Infrastructure/Postgres/PostgreSourceDriver.cpp
    Infrastructure/Postgres/PostgreSourceDriver.h
    Infrastructure/MySql/MySqlSourceException.cpp
    Infrastructure/MySql/MySqlSourceException.h
    Infrastructure/Postgres/PostgreSourceException.cpp
    Infrastructure/Postgres/PostgreSourceException.h Infrastructure/MongoDb/MongoDbSourceDriver.cpp Infrastructure/MongoDb/MongoDbSourceDriver.h Infrastructure/MongoDb/MongoDbSourceException.cpp Infrastructure/MongoDb/MongoDbSourceException.h)


add_library(examples STATIC
    Examples/main.cpp
    Examples/mysql_c_example.h
    Examples/mysql_c_example.cpp)


add_library(apptest STATIC
    AppTest/main.cpp
    AppTest/Store/StockGroupMySqlStore.cpp
    AppTest/Store/StockGroupMySqlStore.h
    AppTest/Store/Test/MySqlStore.hpp
    AppTest/Store/StockGroupPostgreStore.cpp
    AppTest/Store/StockGroupPostgreStore.h AppTest/Store/EnquiryMongoDbStore.cpp AppTest/Store/EnquiryMongoDbStore.h AppTest/Store/Test/MongoDbStore.hpp AppTest/Store/Test/PostgreStore.hpp)


# Libs
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/Libs)

# OPT_LOCAL
set(OPT_LOCAL "/opt/local")
set(OPT_LOCAL_INCLUDE "${OPT_LOCAL}/include")
set(OPT_LOCAL_LIB "${OPT_LOCAL}/lib")

# POSTGRESQL94
include_directories(${OPT_LOCAL_INCLUDE}/postgresql94)
LINK_DIRECTORIES(${OPT_LOCAL_LIB}/postgresql94)

# MySql Client
set(MYSQL_DIR ${LIBS_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64)
include_directories(${MYSQL_DIR}/include)
LINK_DIRECTORIES(${MYSQL_DIR}/lib)

# MongoDb
set(BSON_INCLUDE_DIR "/usr/local/include/libbson-1.0")
set(MONGODB_INCLUDE_DIR "/usr/local/include/libmongoc-1.0")
include_directories(${MONGODB_INCLUDE_DIR})
include_directories(${BSON_INCLUDE_DIR})

# Boost
set(BOOST_DIR ${LIBS_DIR}/boost_1_58_0)
include_directories(${BOOST_DIR})

# Examples
set(EXAMPLES_DIR ${CMAKE_SOURCE_DIR}/Examples)
set(EXAMPLES_SOURCE_FILE ${EXAMPLES_DIR}/main.cpp)


# Examples Target
add_executable(cloud_e_cplus_example ${EXAMPLES_SOURCE_FILE})
target_link_libraries(cloud_e_cplus_example mysqlclient examples)


# Debug Target
add_executable(cloud_e_cplus_debug ${SOURCE_FILES})
target_link_libraries(cloud_e_cplus_debug architecture infrastructure application mysqlclient pq mongoc-1.0)

# AppTest Target (with Google Testing Framework)
set(GTEST_LIB_DIR ${LIBS_DIR}/gtest-1.7.0)
set(APPTEST_SOURCE_FILE ${CMAKE_SOURCE_DIR}/AppTest/main.cpp)
include_directories(${GTEST_LIB_DIR}/include)
LINK_DIRECTORIES(${GTEST_LIB_DIR}/lib)

add_executable(cloud_e_cplus_test ${APPTEST_SOURCE_FILE})
target_link_libraries(cloud_e_cplus_test architecture infrastructure application apptest gtest mysqlclient pq mongoc-1.0)