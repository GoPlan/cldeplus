cmake_minimum_required(VERSION 3.2)
project(cloud_e_cplus)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_cplus_SOURCE_DIR}/Build/bin")
set(CMAKE_BINARY_DIR "/Users/ducanhki/Documents/BitBucket/cloud-e-plus/Build")
set(SOURCE_FILES main.cpp)


include_directories(${CMAKE_SOURCE_DIR})


add_library(foundation STATIC
    Cloude.h
    Foundation/Data/cldeValueType.h
    Foundation/Column.cpp
    Foundation/Column.h
    Foundation/Field.cpp
    Foundation/Field.h
    Foundation/Identity.cpp
    Foundation/Identity.h
    Foundation/Entity.cpp
    Foundation/Entity.h
    Foundation/EntityMap.cpp
    Foundation/EntityMap.h
    Foundation/EntityLoader.cpp
    Foundation/EntityLoader.h
    Foundation/EntityStore.cpp
    Foundation/EntityStore.h
    Foundation/Exception/cldeNonSupportedDataTypeException.cpp
    Foundation/Exception/cldeNonSupportedDataTypeException.h
    Foundation/Exception/cldeDataSourceRoutineException.cpp
    Foundation/Exception/cldeDataSourceRoutineException.h
    Foundation/Exception/cldeEntityStoreRoutineException.cpp
    Foundation/Exception/cldeEntityStoreRoutineException.h
    Foundation/Helper/SqlGenerator.cpp
    Foundation/Helper/SqlGenerator.h
    Foundation/Exception/cldeEntityException.cpp
    Foundation/Exception/cldeEntityException.h
    Foundation/EntitySourceDriver.cpp
    Foundation/EntitySourceDriver.h
    Foundation/Helper/EntityStoreHelper.cpp
    Foundation/Helper/EntityStoreHelper.h
    Foundation/Common/IPrintable.h
    Foundation/EntityProxy.cpp
    Foundation/EntityProxy.h
    Foundation/EntityQuery.cpp
    Foundation/EntityQuery.h
    Foundation/Query/Predication.cpp
    Foundation/Query/Predication.h
    Foundation/Query/Comparator/And.cpp
    Foundation/Query/Comparator/And.h
    Foundation/Query/Comparator/Or.cpp
    Foundation/Query/Comparator/Or.h
    Foundation/Query/Comparator/Equal.cpp
    Foundation/Query/Comparator/Equal.h
    Foundation/Query/Comparator/Greater.cpp
    Foundation/Query/Comparator/Greater.h
    Foundation/Query/Comparator/GreaterOrEqual.cpp
    Foundation/Query/Comparator/GreaterOrEqual.h
    Foundation/Query/Comparator/Lesser.cpp
    Foundation/Query/Comparator/Lesser.h
    Foundation/Query/Comparator/LesserOrEqual.cpp
    Foundation/Query/Comparator/LesserOrEqual.h
    Foundation/Query/Comparator/NotEqual.cpp
    Foundation/Query/Comparator/NotEqual.h
    Foundation/Query/Comparator/Like.cpp
    Foundation/Query/Comparator/Like.h
    Foundation/Query/Comparator/NotLike.cpp
    Foundation/Query/Comparator/NotLike.h
    Foundation/Query/Comparator/IsNull.cpp
    Foundation/Query/Comparator/IsNull.h
    Foundation/Query/Comparator/IsNotNull.cpp
    Foundation/Query/Comparator/IsNotNull.h
    Foundation/Query/Enumeration/ComparatorType.cpp
    Foundation/Query/Enumeration/ComparatorType.h Foundation/Query/Enumeration/ComparatorType.cpp Foundation/Common/IEquatable.h Foundation/Data/cldeValue.cpp Foundation/Data/cldeValue.h Foundation/Data/cldeValueType.cpp Foundation/Data/Implementation/cldeInt32.cpp Foundation/Data/Implementation/cldeInt32.h Foundation/Data/Implementation/cldeInt64.cpp Foundation/Data/Implementation/cldeInt64.h Foundation/Data/Implementation/cldeVarchar.cpp Foundation/Data/Implementation/cldeVarchar.h Foundation/Data/Implementation/cldeDouble.cpp Foundation/Data/Implementation/cldeDouble.h Foundation/Data/Implementation/cldeText.cpp Foundation/Data/Implementation/cldeText.h Foundation/Data/Implementation/cldeInt16.cpp Foundation/Data/Implementation/cldeInt16.h Foundation/Data/cldeNumericValue.cpp Foundation/Data/cldeNumericValue.h Foundation/Data/cldeCharacterValue.cpp Foundation/Data/cldeCharacterValue.h Foundation/Data/Implementation/cldeFloat.cpp Foundation/Data/Implementation/cldeFloat.h Foundation/Data/Implementation/cldePoint.cpp Foundation/Data/Implementation/cldePoint.h Foundation/Data/Implementation/cldeMatrix.cpp Foundation/Data/Implementation/cldeMatrix.h Foundation/Data/cldeValueFactory.cpp Foundation/Data/cldeValueFactory.h Foundation/Common/IComputable.h Foundation/Common/ICompoundAssignable.h Foundation/Data/Implementation/cldeString.cpp Foundation/Data/Implementation/cldeString.h Foundation/Exception/cldeNonSupportedFunctionException.cpp Foundation/Exception/cldeNonSupportedFunctionException.h Foundation/Exception/cldeException.cpp Foundation/Exception/cldeException.h Foundation/Data/cldeData.h Foundation/Common/IParsable.h)


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
    Application/Mapper/SequenceLoader.h
    Application/Model/Enquiry.cpp
    Application/Model/Enquiry.h
    Application/Mapper/EnquiryMap.cpp
    Application/Mapper/EnquiryMap.h
    Application/Mapper/EnquiryLoader.cpp
    Application/Mapper/EnquiryLoader.h)


add_library(sourcedriver STATIC
    SourceDriver/MySql/MySqlSourceDriver.h
    SourceDriver/MySql/MySqlSourceDriver.cpp
    SourceDriver/Postgres/PostgreSourceDriver.cpp
    SourceDriver/Postgres/PostgreSourceDriver.h
    SourceDriver/Postgres/PostgreSourceDriver.cpp
    SourceDriver/Postgres/PostgreSourceDriver.h
    SourceDriver/MySql/MySqlSourceException.cpp
    SourceDriver/MySql/MySqlSourceException.h
    SourceDriver/Postgres/PostgreSourceException.cpp
    SourceDriver/Postgres/PostgreSourceException.h
    SourceDriver/MongoDb/MongoDbSourceDriver.cpp
    SourceDriver/MongoDb/MongoDbSourceDriver.h
    SourceDriver/MongoDb/MongoDbSourceException.cpp
    SourceDriver/MongoDb/MongoDbSourceException.h
    SourceDriver/SQLite/SQLiteSourceDriver.cpp
    SourceDriver/SQLite/SQLiteSourceDriver.h
    SourceDriver/SQLite/SQLiteSourceException.cpp
    SourceDriver/SQLite/SQLiteSourceException.h
    SourceDriver/SQLite/Amalgamation/sqlite3.h
    SourceDriver/SQLite/Amalgamation/sqlite3ext.h
    SourceDriver/SQLite/Amalgamation/sqlite3.c)


add_library(examples STATIC
    Examples/main.cpp
    Examples/mysql_c_example.h
    Examples/mysql_c_example.cpp
    Examples/mongodb_c_example.cpp
    Examples/mongodb_c_example.h)


add_library(apptest STATIC
    AppTest/main.cpp
    AppTest/Store/StockGroupMySqlStore.cpp
    AppTest/Store/StockGroupMySqlStore.h
    AppTest/Store/StockGroupPostgreStore.cpp
    AppTest/Store/StockGroupPostgreStore.h
    AppTest/Store/EnquiryMongoDbStore.cpp
    AppTest/Store/EnquiryMongoDbStore.h
    AppTest/Store/EnquirySQLiteStore.cpp
    AppTest/Store/EnquirySQLiteStore.h
    AppTest/Store/Test/MongoDbStore.hpp
    AppTest/Store/Test/PostgreStore.hpp
    AppTest/Store/Test/SQLiteStore.hpp
    AppTest/Store/Test/MySqlStore.hpp)


# Libs
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/Libs)


# /opt/local
set(OPT_LOCAL "/opt/local")
set(OPT_LOCAL_INCLUDE "${OPT_LOCAL}/include")
set(OPT_LOCAL_LIB "${OPT_LOCAL}/lib")


# PostgreSql94
include_directories(${OPT_LOCAL_INCLUDE}/postgresql94)
LINK_DIRECTORIES(${OPT_LOCAL_LIB}/postgresql94)


# MySql
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
target_link_libraries(cloud_e_cplus_example examples mysqlclient mongoc-1.0 bson-1.0)


# Debug Target
add_executable(cloud_e_cplus_debug ${SOURCE_FILES})
target_link_libraries(cloud_e_cplus_debug foundation sourcedriver application mysqlclient pq mongoc-1.0)


# AppTest Target (with Google Testing Foundation)
set(GTEST_LIB_DIR ${LIBS_DIR}/gtest-1.7.0)
set(APPTEST_SOURCE_FILE ${CMAKE_SOURCE_DIR}/AppTest/main.cpp)
include_directories(${GTEST_LIB_DIR}/include)
LINK_DIRECTORIES(${GTEST_LIB_DIR}/lib)

add_executable(cloud_e_cplus_test ${APPTEST_SOURCE_FILE})
target_link_libraries(cloud_e_cplus_test foundation sourcedriver application apptest)
target_link_libraries(cloud_e_cplus_test gtest mysqlclient pq mongoc-1.0 bson-1.0)