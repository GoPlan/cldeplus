cmake_minimum_required(VERSION 3.2)
project(cloud_e_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

add_library(relation STATIC
    Relation.h
    NamedEntityLoader.cpp
    NamedEntityLoader.h
    RelationMap.cpp
    RelationMap.h
    Link.cpp
    Link.h
    LinkToOne.cpp
    LinkToOne.h
    LinkToMany.cpp
    LinkToMany.h
    NamedEntityStore.cpp
    NamedEntityStore.h
    Exception/NamedEntityStoreException.cpp
    Exception/NamedEntityStoreException.h
)