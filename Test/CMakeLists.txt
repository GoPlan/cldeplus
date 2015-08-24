cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(GTEST_LIB_DIR ".local/gtest-1.7.0")

include_directories(${CMAKE_SOURCE_DIR})
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
        Entity/PreOrderItems.cpp
        Entity/PreOrderItems.h
)

add_library(apptest STATIC
        Store/SQLiteStore.hpp
        Store/MySqlStore00.hpp
        Store/MySqlStore01.hpp
        Store/MySqlStore02.hpp
        Type/ValueComparison.hpp
        Type/CreateValue.hpp
        Segmentation/Segmentation.hpp
        Segmentation/Transformation.hpp
        Relation/NamedEntity01.hpp
        Relation/NamedEntity02.hpp
        Relation/Relation.hpp
        Store/Preparation/ProductSQLiteStore.cpp
        Store/Preparation/ProductSQLiteStore.h
        Store/Preparation/PreOrderMySqlStore.cpp
        Store/Preparation/PreOrderMySqlStore.h
        Store/Preparation/EnquiryMySqlStore.cpp
        Store/Preparation/EnquiryMySqlStore.h
)

