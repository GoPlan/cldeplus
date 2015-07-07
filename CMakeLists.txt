cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${cloud_e_plus_SOURCE_DIR}/.local/build/bin")
set(SOURCE_FILES main.cpp)


include_directories(${CMAKE_SOURCE_DIR})


add_library(foundation STATIC
    Cloude.h
    Foundation/Data/TypeEnums.h
    Foundation/Column.cpp
    Foundation/Column.h
    Foundation/Cell.cpp
    Foundation/Cell.h
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
    Foundation/Exception/cldeEntityException.cpp
    Foundation/Exception/cldeEntityException.h
    Foundation/EntitySourceDriver.cpp
    Foundation/EntitySourceDriver.h
    Foundation/Common/IPrintable.h
    Foundation/Query/Criteria.cpp
    Foundation/Query/Criteria.h
    Foundation/Query/Helper/SqlHelper.cpp
    Foundation/Query/Helper/SqlHelper.h
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
    Foundation/Query/ComparativeType.cpp
    Foundation/Query/ComparativeType.h
    Foundation/Data/Value.cpp
    Foundation/Data/Value.h
    Foundation/Data/TypeEnums.cpp
    Foundation/Data/NumericValue.cpp
    Foundation/Data/NumericValue.h
    Foundation/Data/CharacterValue.cpp
    Foundation/Data/CharacterValue.h
    Foundation/Data/ValueFactory.cpp
    Foundation/Data/ValueFactory.h
    Foundation/Data/TypeIncludes.h
    Foundation/Data/Helper/ValueHelper.cpp
    Foundation/Data/Helper/ValueHelper.h
    Foundation/Data/Type/Int32.cpp
    Foundation/Data/Type/Int32.h
    Foundation/Data/Type/Int64.cpp
    Foundation/Data/Type/Int64.h
    Foundation/Data/Type/VarChar.cpp
    Foundation/Data/Type/VarChar.h
    Foundation/Data/Type/Double.cpp
    Foundation/Data/Type/Double.h
    Foundation/Data/Type/Text.cpp
    Foundation/Data/Type/Text.h
    Foundation/Data/Type/Int16.cpp
    Foundation/Data/Type/Int16.h
    Foundation/Data/Type/Boolean.cpp
    Foundation/Data/Type/Boolean.h
    Foundation/Data/Type/Date.cpp
    Foundation/Data/Type/Date.h
    Foundation/Data/Type/DateTime.cpp
    Foundation/Data/Type/DateTime.h
    Foundation/Data/Type/Time.cpp
    Foundation/Data/Type/Time.h
    Foundation/Data/Type/UInt16.cpp
    Foundation/Data/Type/UInt16.h
    Foundation/Data/Type/UInt32.cpp
    Foundation/Data/Type/UInt32.h
    Foundation/Data/Type/UInt64.cpp
    Foundation/Data/Type/UInt64.h
    Foundation/Data/Type/Byte.cpp
    Foundation/Data/Type/Byte.h
    Foundation/Data/Type/TimeStamp.cpp
    Foundation/Data/Type/TimeStamp.h
    Foundation/Data/Type/Currency.cpp
    Foundation/Data/Type/Currency.h
    Foundation/Data/Type/Float.cpp
    Foundation/Data/Type/Float.h
    Foundation/Data/Type/Point.cpp
    Foundation/Data/Type/Point.h
    Foundation/Data/Type/Matrix.cpp
    Foundation/Data/Type/Matrix.h
    Foundation/Data/Type/String.cpp
    Foundation/Data/Type/String.h
    Foundation/Data/Type/Blob.cpp
    Foundation/Data/Type/Blob.h
    Foundation/Data/Comparer/Comparer.cpp
    Foundation/Data/Comparer/Comparer.h
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
    Foundation/Query/CriteriaLeaf.cpp
    Foundation/Query/CriteriaLeaf.h
    Foundation/Query/Query.h
    Foundation/Query/CriteriaComposite.cpp
    Foundation/Query/CriteriaComposite.h
    Foundation/Query/CriteriaIterator.cpp
    Foundation/Query/CriteriaIterator.h
    Foundation/Query/Helper/CriteriaHelper.cpp
    Foundation/Query/Helper/CriteriaHelper.h
    Foundation/Enum/CommonBufferSize.h
    Foundation/Store/AbstractEntity.h
    Foundation/Store/AbstractEntity.cpp
    Foundation/EntityRelationship.cpp
    Foundation/EntityRelationship.h
    Foundation/EntityLink.cpp
    Foundation/EntityLink.h
    Foundation/Query/Helper/ProxyHelper.cpp
    Foundation/Query/Helper/ProxyHelper.h
    Foundation/Exception/cldeSegmentationException.cpp
    Foundation/Exception/cldeSegmentationException.h
    Foundation/Data/Comparer/Less.cpp
    Foundation/Data/Comparer/Less.h
    Foundation/Data/Comparer/Greater.cpp
    Foundation/Data/Comparer/Greater.h
    Foundation/Data/Comparer/Compare.cpp
    Foundation/Data/Comparer/Compare.h
    Foundation/Store/Helper/EntityStoreHelper.cpp
    Foundation/Store/Helper/EntityStoreHelper.h
    Foundation/Store/Helper/CellHelper.cpp
    Foundation/Store/Helper/CellHelper.h
    Foundation/Store/Comparer/Compare.cpp
    Foundation/Store/Comparer/Compare.h
    Foundation/Store/Comparer/Greater.cpp
    Foundation/Store/Comparer/Greater.h
    Foundation/Store/Comparer/Less.cpp
    Foundation/Store/Comparer/Less.h
    Foundation/Data/Helper/TypeHelper.cpp
    Foundation/Data/Helper/TypeHelper.h)

add_library(relation STATIC


Relation/RelationMap.cpp Relation/RelationMap.h Relation/RelationFetcher.cpp Relation/RelationFetcher.h)

add_library(segmentation STATIC
    Segmentation/Join/Inner.cpp
    Segmentation/Join/Inner.h
    Segmentation/Join/Cross.cpp
    Segmentation/Join/Cross.h
    Segmentation/Join/Left.cpp
    Segmentation/Join/Left.h
    Segmentation/Join/Right.cpp
    Segmentation/Join/Right.h
    Segmentation/Transformation/EntityTransformer.cpp
    Segmentation/Transformation/EntityTransformer.h
    Segmentation/Transformation/CellTransformer.cpp
    Segmentation/Transformation/CellTransformer.h
    Segmentation/Transformation/TypeCaster.cpp
    Segmentation/Transformation/TypeCaster.h
    Segmentation/Transformation/Caster/DoubleCaster.cpp
    Segmentation/Transformation/Caster/DoubleCaster.h
    Segmentation/Transformation/Caster/Int64Caster.cpp
    Segmentation/Transformation/Caster/Int64Caster.h
    Segmentation/Transformation/Caster/Int32Caster.cpp
    Segmentation/Transformation/Caster/Int32Caster.h
    Segmentation/Transformation/Caster/FloatCaster.cpp
    Segmentation/Transformation/Caster/FloatCaster.h
    Segmentation/Transformation/Caster/Int16Caster.cpp
    Segmentation/Transformation/Caster/Int16Caster.h
    Segmentation/Transformation/Caster/UInt16Caster.cpp
    Segmentation/Transformation/Caster/UInt16Caster.h
    Segmentation/Transformation/Caster/UInt32Caster.cpp
    Segmentation/Transformation/Caster/UInt32Caster.h
    Segmentation/Transformation/Caster/UInt64Caster.cpp
    Segmentation/Transformation/Caster/UInt64Caster.h
    Segmentation/Exception/SegmentationException.cpp
    Segmentation/Exception/SegmentationException.h
    Segmentation/Exception/TransformationException.cpp
    Segmentation/Exception/TransformationException.h
    Segmentation/Segmentation.h
    Segmentation/Transformation/Caster/BooleanCaster.cpp
    Segmentation/Transformation/Caster/BooleanCaster.h
    Segmentation/Transformation/Caster/ByteCaster.cpp
    Segmentation/Transformation/Caster/ByteCaster.h
    Segmentation/Transformation/Caster/StringCaster.cpp
    Segmentation/Transformation/Caster/StringCaster.h
    Segmentation/Transformation/Caster/VarCharCaster.cpp
    Segmentation/Transformation/Caster/VarCharCaster.h
    Segmentation/CasterFactory.cpp
    Segmentation/CasterFactory.h Segmentation/Join/Full.cpp Segmentation/Join/Full.h)


add_library(Drivers STATIC
    Drivers/SQLite/SQLiteSourceDriver.cpp
    Drivers/SQLite/SQLiteSourceDriver.h
    Drivers/SQLite/SQLiteSourceException.cpp
    Drivers/SQLite/SQLiteSourceException.h
    Drivers/SQLite/Amalgamation/sqlite3.h
    Drivers/SQLite/Amalgamation/sqlite3ext.h
    Drivers/SQLite/Amalgamation/sqlite3.c
#    Drivers/MongoDb/MongoDbSourceDriver.cpp
#    Drivers/MongoDb/MongoDbSourceDriver.h
#    Drivers/MongoDb/MongoDbSourceException.cpp
#    Drivers/MongoDb/MongoDbSourceException.h
#    Drivers/Postgres/PostgreSourceDriver.cpp
#    Drivers/Postgres/PostgreSourceDriver.h
#    Drivers/Postgres/PostgreSourceException.cpp
#    Drivers/Postgres/PostgreSourceException.h
#    Drivers/MySql/MySqlSourceDriver.h
#    Drivers/MySql/MySqlSourceDriver.cpp
#    Drivers/MySql/MySqlSourceException.cpp
#    Drivers/MySql/MySqlSourceException.h
#    Drivers/DynamoDb/DynamoDbSourceDriver.cpp
#    Drivers/DynamoDb/DynamoDbSourceDriver.h
#    Drivers/DynamoDb/DynamoDbSourceException.cpp
#    Drivers/DynamoDb/DynamoDbSourceException.h
    Drivers/SQLite/SQLiteSourceHelper.cpp
    Drivers/SQLite/SQLiteSourceHelper.h
    )


add_library(application STATIC
    AppTest/Application/StockGroupMap.cpp
    AppTest/Application/StockGroupMap.h
    AppTest/Application/StockGroupLoader.cpp
    AppTest/Application/StockGroupLoader.h
    AppTest/Application/EnquiryMap.cpp
    AppTest/Application/EnquiryMap.h
    AppTest/Application/EnquiryLoader.cpp
    AppTest/Application/EnquiryLoader.h
    AppTest/Application/PreOrderMap.cpp
    AppTest/Application/PreOrderMap.h
    AppTest/Application/CustomerMap.cpp
    AppTest/Application/CustomerMap.h
    AppTest/Application/ProductMap.cpp
    AppTest/Application/ProductMap.h
    AppTest/Application/OrderItemsMap.cpp
    AppTest/Application/OrderItemsMap.h AppTest/Application/CustomerLoader.cpp AppTest/Application/CustomerLoader.h AppTest/Application/PreOrderLoader.cpp AppTest/Application/PreOrderLoader.h)


add_library(apptest STATIC
    AppTest/main.cpp
    AppTest/Store/Preparation/EnquirySQLiteStore.cpp
    AppTest/Store/Preparation/EnquirySQLiteStore.h
    AppTest/Store/SQLiteStore.hpp
#    AppTest/Store/EnquiryMongoDbStore.cpp
#    AppTest/Store/EnquiryMongoDbStore.h
#    AppTest/Store/Test/MongoDbStore.hpp
#    AppTest/Store/StockGroupMySqlStore.cpp
#    AppTest/Store/StockGroupMySqlStore.h
#    AppTest/Store/Test/MySqlStore.hpp
#    AppTest/Store/StockGroupPostgreStore.cpp
#    AppTest/Store/StockGroupPostgreStore.h
#    AppTest/Store/Test/PostgreStore.hpp
    AppTest/Query/Criteria.hpp
    AppTest/Segmentation/Segmentation.hpp
    AppTest/Type/CreateValue.hpp
    AppTest/Type/ValueComparison.hpp
    AppTest/Segmentation/Transformation.hpp)


add_library(.examples STATIC
    .examples/main.cpp
    .examples/mysql_c_example.h
    .examples/mysql_c_example.cpp
    .examples/mongodb_c_example.cpp
    .examples/mongodb_c_example.h
    )


# Libs
set(LOCAL_DIR ${CMAKE_SOURCE_DIR}/.local)
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


# .examples Target
set(EXAMPLES_DIR ${CMAKE_SOURCE_DIR}/.examples)
set(EXAMPLES_SOURCE_FILE ${EXAMPLES_DIR}/main.cpp)
add_executable(cloud_e_plus_example ${EXAMPLES_SOURCE_FILE})
target_link_libraries(cloud_e_plus_example .examples mysqlclient mongoc-1.0 bson-1.0)


# Debug Target
add_executable(cloud_e_plus_debug ${SOURCE_FILES})
target_link_libraries(cloud_e_plus_debug foundation Drivers application mysqlclient pq mongoc-1.0)


# AppTest Target (with Google Testing Foundation)
set(GTEST_LIB_DIR ${LIBS_DIR}/gtest-1.7.0)
set(APPTEST_SOURCE_FILE ${CMAKE_SOURCE_DIR}/AppTest/main.cpp)
include_directories(${GTEST_LIB_DIR}/include)
LINK_DIRECTORIES(${GTEST_LIB_DIR}/lib)
add_executable(cloud_e_plus_test ${APPTEST_SOURCE_FILE})
target_link_libraries(cloud_e_plus_test foundation segmentation)
target_link_libraries(cloud_e_plus_test Drivers)
#target_link_libraries(cloud_e_plus_test mysqlclient pq mongoc-1.0 bson-1.0)
target_link_libraries(cloud_e_plus_test application apptest gtest)