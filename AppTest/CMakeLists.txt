cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(GTEST_LIB_DIR ".local/gtest-1.7.0")
include_directories(${GTEST_LIB_DIR}/include)

add_library(application STATIC
    Application/EnquiryMap.cpp
    Application/EnquiryMap.h
    Application/PreOrderMap.cpp
    Application/PreOrderMap.h
    Application/CustomerMap.cpp
    Application/CustomerMap.h
    Application/ProductMap.cpp
    Application/ProductMap.h
    Application/PreOrderItemsMap.cpp
    Application/PreOrderItemsMap.h
    Entity/Customer.cpp
    Entity/Customer.h
    Entity/PreOrder.cpp
    Entity/PreOrder.h
    Entity/Enquiry.cpp
    Entity/Enquiry.h
Entity/PreOrderItems.cpp Entity/PreOrderItems.h)

add_library(apptest STATIC
    Store/Preparation/EnquirySQLiteStore.cpp
    Store/Preparation/EnquirySQLiteStore.h
    Store/Preparation/PreOrderMySqlStore.cpp
    Store/Preparation/PreOrderMySqlStore.h
#   Store/EnquiryMongoDbStore.cpp
#   Store/EnquiryMongoDbStore.h
#   Store/StockGroupPostgreStore.cpp
#   Store/StockGroupPostgreStore.h
#   Store/MongoDbStore.hpp
#   Store/MySqlStore.hpp
#   Store/PostgreStore.hpp
#   Store/SQLiteStore.hpp
#   Segmentation/Transformation.hpp
#   Segmentation/Segmentation.hpp
#   Relation/Relation.hpp
#   Relation/NamedEntity01.hpp
#   Relation/NamedEntity02.hpp
#   Query/Criteria.hpp
#   Type/CreateValue.hpp
#   Type/ValueComparison.hpp
)

