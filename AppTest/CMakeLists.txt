cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(GTEST_LIB_DIR ".local/gtest-1.7.0")
include_directories(${GTEST_LIB_DIR}/include)

add_library(application STATIC
    Application/StockGroupMap.cpp
    Application/StockGroupMap.h
    Application/EnquiryMap.cpp
    Application/EnquiryMap.h
    Application/PreOrderMap.cpp
    Application/PreOrderMap.h
    Application/CustomerMap.cpp
    Application/CustomerMap.h
    Application/ProductMap.cpp
    Application/ProductMap.h
    Application/OrderItemsMap.cpp
    Application/OrderItemsMap.h
    Entity/Customer.cpp
    Entity/Customer.h
    Entity/PreOrder.cpp
    Entity/PreOrder.h
    Entity/Enquiry.cpp
    Entity/Enquiry.h)

add_library(apptest STATIC
    Store/Preparation/EnquirySQLiteStore.cpp
    Store/Preparation/EnquirySQLiteStore.h
#   Store/EnquiryMongoDbStore.cpp
#   Store/EnquiryMongoDbStore.h
#   Store/Test/MongoDbStore.hpp
#   Store/StockGroupMySqlStore.cpp
#   Store/StockGroupMySqlStore.h
#   Store/Test/MySqlStore.hpp
#   Store/StockGroupPostgreStore.cpp
#   Store/StockGroupPostgreStore.h
#   Store/Test/PostgreStore.hpp
#    Store/SQLiteStore.hpp
#    Query/Criteria.hpp
#    Segmentation/Segmentation.hpp
#    Type/CreateValue.hpp
#    Type/ValueComparison.hpp
#    Segmentation/Transformation.hpp
#    Relation/NamedEntity01.hpp
#    Relation/NamedEntity02.hpp
#    Relation/Relation.hpp
    )

