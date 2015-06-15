cmake_minimum_required(VERSION 3.2)
project(cloud_e_cplus)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_cplus_SOURCE_DIR}/local/build/bin")
set(SOURCE_FILES main.cpp)


include_directories(${CMAKE_SOURCE_DIR})


add_library(foundation STATIC
    Cloude.h
    Foundation/Type/cldeValueType.h
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
    Foundation/EntityProxy.cpp
    Foundation/EntityProxy.h
    Foundation/EntityQuery.cpp
    Foundation/EntityQuery.h
    Foundation/Exception/cldeNonSupportedDataTypeException.cpp
    Foundation/Exception/cldeNonSupportedDataTypeException.h
    Foundation/Exception/cldeDataSourceRoutineException.cpp
    Foundation/Exception/cldeDataSourceRoutineException.h
    Foundation/Exception/cldeEntityStoreRoutineException.cpp
    Foundation/Exception/cldeEntityStoreRoutineException.h
    Foundation/Query/SqlGenerator.cpp
    Foundation/Query/SqlGenerator.h
    Foundation/Exception/cldeEntityException.cpp
    Foundation/Exception/cldeEntityException.h
    Foundation/EntitySourceDriver.cpp
    Foundation/EntitySourceDriver.h
    Foundation/Store/EntityStoreHelper.cpp
    Foundation/Store/EntityStoreHelper.h
    Foundation/Common/IPrintable.h
    Foundation/Query/Predicate.cpp
    Foundation/Query/Predicate.h
    Foundation/Query/Comparative/And.cpp
    Foundation/Query/Comparative/And.h
    Foundation/Query/Comparative/Or.cpp
    Foundation/Query/Comparative/Or.h
    Foundation/Query/Comparative/Equal.cpp
    Foundation/Query/Comparative/Equal.h
    Foundation/Query/Comparative/Greater.cpp
    Foundation/Query/Comparative/Greater.h
    Foundation/Query/Comparative/GreaterOrEqual.cpp
    Foundation/Query/Comparative/GreaterOrEqual.h
    Foundation/Query/Comparative/Lesser.cpp
    Foundation/Query/Comparative/Lesser.h
    Foundation/Query/Comparative/LesserOrEqual.cpp
    Foundation/Query/Comparative/LesserOrEqual.h
    Foundation/Query/Comparative/NotEqual.cpp
    Foundation/Query/Comparative/NotEqual.h
    Foundation/Query/Comparative/Like.cpp
    Foundation/Query/Comparative/Like.h
    Foundation/Query/Comparative/NotLike.cpp
    Foundation/Query/Comparative/NotLike.h
    Foundation/Query/Comparative/IsNull.cpp
    Foundation/Query/Comparative/IsNull.h
    Foundation/Query/Comparative/IsNotNull.cpp
    Foundation/Query/Comparative/IsNotNull.h
    Foundation/Query/Enumeration/ComparativeType.cpp
    Foundation/Query/Enumeration/ComparativeType.h
    Foundation/Type/cldeValue.cpp
    Foundation/Type/cldeValue.h
    Foundation/Type/cldeValueType.cpp
    Foundation/Type/Implementation/cldeInt32.cpp
    Foundation/Type/Implementation/cldeInt32.h
    Foundation/Type/Implementation/cldeInt64.cpp
    Foundation/Type/Implementation/cldeInt64.h
    Foundation/Type/Implementation/cldeVarchar.cpp
    Foundation/Type/Implementation/cldeVarchar.h
    Foundation/Type/Implementation/cldeDouble.cpp
    Foundation/Type/Implementation/cldeDouble.h
    Foundation/Type/Implementation/cldeText.cpp
    Foundation/Type/Implementation/cldeText.h
    Foundation/Type/Implementation/cldeInt16.cpp
    Foundation/Type/Implementation/cldeInt16.h
    Foundation/Type/cldeNumericValue.cpp
    Foundation/Type/cldeNumericValue.h
    Foundation/Type/cldeCharacterValue.cpp
    Foundation/Type/cldeCharacterValue.h
    Foundation/Type/Implementation/cldeFloat.cpp
    Foundation/Type/Implementation/cldeFloat.h
    Foundation/Type/Implementation/cldePoint.cpp
    Foundation/Type/Implementation/cldePoint.h
    Foundation/Type/Implementation/cldeMatrix.cpp
    Foundation/Type/Implementation/cldeMatrix.h
    Foundation/Type/cldeValueFactory.cpp
    Foundation/Type/cldeValueFactory.h
    Foundation/Type/cldeData.h
    Foundation/Type/Implementation/cldeString.cpp
    Foundation/Type/Implementation/cldeString.h
    Foundation/Exception/cldeNonSupportedFunctionException.cpp
    Foundation/Exception/cldeNonSupportedFunctionException.h
    Foundation/Exception/cldeException.cpp
    Foundation/Exception/cldeException.h
    Foundation/Common/IEquatable.h
    Foundation/Common/IComputable.h
    Foundation/Common/ICompoundAssignable.h
    Foundation/Common/IParsable.h
    Foundation/Common/IFormattable.h
    Foundation/Query/Contract/IPredicateFormatter.h
    Foundation/Query/Comparative.h
    Foundation/Query/PredicateLeaf.cpp
    Foundation/Query/PredicateLeaf.h
    Foundation/Query/Query.h
    Foundation/Query/PredicateComposite.cpp Foundation/Query/PredicateComposite.h Foundation/Query/PredicateSentinel.cpp Foundation/Query/PredicateSentinel.h Foundation/Query/PredicateIterator.cpp Foundation/Query/PredicateIterator.h Foundation/Query/Helper/PredicateHelper.cpp Foundation/Query/Helper/PredicateHelper.h)


add_library(application STATIC
    Application/Mapper/StockGroupMap.cpp
    Application/Mapper/StockGroupMap.h
    Application/Mapper/StockGroupLoader.cpp
    Application/Mapper/StockGroupLoader.h
    Application/Mapper/EnquiryMap.cpp
    Application/Mapper/EnquiryMap.h
    Application/Mapper/EnquiryLoader.cpp
    Application/Mapper/EnquiryLoader.h
    )


add_library(sourcedriver STATIC
    SourceDriver/SQLite/SQLiteSourceDriver.cpp
    SourceDriver/SQLite/SQLiteSourceDriver.h
    SourceDriver/SQLite/SQLiteSourceException.cpp
    SourceDriver/SQLite/SQLiteSourceException.h
    SourceDriver/SQLite/Amalgamation/sqlite3.h
    SourceDriver/SQLite/Amalgamation/sqlite3ext.h
    SourceDriver/SQLite/Amalgamation/sqlite3.c
#    SourceDriver/MongoDb/MongoDbSourceDriver.cpp
#    SourceDriver/MongoDb/MongoDbSourceDriver.h
#    SourceDriver/MongoDb/MongoDbSourceException.cpp
#    SourceDriver/MongoDb/MongoDbSourceException.h
#    SourceDriver/Postgres/PostgreSourceDriver.cpp
#    SourceDriver/Postgres/PostgreSourceDriver.h
#    SourceDriver/Postgres/PostgreSourceException.cpp
#    SourceDriver/Postgres/PostgreSourceException.h
#    SourceDriver/MySql/MySqlSourceDriver.h
#    SourceDriver/MySql/MySqlSourceDriver.cpp
#    SourceDriver/MySql/MySqlSourceException.cpp
#    SourceDriver/MySql/MySqlSourceException.h
#    SourceDriver/DynamoDb/DynamoDbSourceDriver.cpp
#    SourceDriver/DynamoDb/DynamoDbSourceDriver.h
#    SourceDriver/DynamoDb/DynamoDbSourceException.cpp
#    SourceDriver/DynamoDb/DynamoDbSourceException.h
    )


add_library(apptest STATIC
    AppTest/main.cpp
    AppTest/Store/EnquirySQLiteStore.cpp
    AppTest/Store/EnquirySQLiteStore.h
    AppTest/Store/Test/SQLiteStore.hpp
#    AppTest/Store/EnquiryMongoDbStore.cpp
#    AppTest/Store/EnquiryMongoDbStore.h
#    AppTest/Store/Test/MongoDbStore.hpp
#    AppTest/Store/StockGroupMySqlStore.cpp
#    AppTest/Store/StockGroupMySqlStore.h
#    AppTest/Store/Test/MySqlStore.hpp
#    AppTest/Store/StockGroupPostgreStore.cpp
#    AppTest/Store/StockGroupPostgreStore.h
#    AppTest/Store/Test/PostgreStore.hpp
    AppTest/Query/Predicate.hpp
    )



add_library(examples STATIC
    Examples/main.cpp
    Examples/mysql_c_example.h
    Examples/mysql_c_example.cpp
    Examples/mongodb_c_example.cpp
    Examples/mongodb_c_example.h
    )



# Libs
set(LOCAL_DIR ${CMAKE_SOURCE_DIR}/local)
set(LIBS_DIR ${LOCAL_DIR}/libs)


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


# Examples Target
set(EXAMPLES_DIR ${CMAKE_SOURCE_DIR}/Examples)
set(EXAMPLES_SOURCE_FILE ${EXAMPLES_DIR}/main.cpp)
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
target_link_libraries(cloud_e_cplus_test foundation)
target_link_libraries(cloud_e_cplus_test sourcedriver mysqlclient pq mongoc-1.0 bson-1.0)
target_link_libraries(cloud_e_cplus_test application apptest gtest)