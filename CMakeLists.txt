cmake_minimum_required(VERSION 3.2)
project(cldeplus)


# Build variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VERSION 0.7.0)


# Directories
set(EXTRA_DIR "${CMAKE_SOURCE_DIR}/Extra")
set(GTEST "${EXTRA_DIR}/gtest-1.7.0")
set(CLDEPARSER "${EXTRA_DIR}/cldeparser-1.0.0")


# SOURCE - Core
file(GLOB_RECURSE FOUNDATION_SOURCE
        Source/Foundation/*.cpp
        Source/Foundation/*.h
        Source/Foundation/*.hpp
)

file(GLOB_RECURSE RELATION_SOURCE
        Source/Relation/*.cpp
        Source/Relation/*.h
        Source/Relation/*.hpp
)

file(GLOB_RECURSE SEGMENTATION_SOURCE
        Source/Segmentation/*.cpp
        Source/Segmentation/*.h
        Source
)


# SOURCE - Drivers
file(GLOB_RECURSE DRIVERS_MYSQL
        Source/Drivers/MySql/*.cpp
        Source/Drivers/MySql/*.h
)

file(GLOB_RECURSE DRIVERS_SQLITE
        Source/Drivers/SQLite/*.cpp
        Source/Drivers/SQLite/*.h
        Source/Drivers/SQLite/Amalgamation/*
)

set(COMPLETE_SOURCE
        ${FOUNDATION_SOURCE}
        ${RELATION_SOURCE}
        ${SEGMENTATION_SOURCE}
        ${DRIVERS_SQLITE}
        ${DRIVERS_MYSQL}
        Source/cldeplus.h)

include_directories(${EXTRA_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64/include)
link_directories(${EXTRA_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64/lib)

add_library(cldeplus-static STATIC ${COMPLETE_SOURCE})
add_library(cldeplus SHARED ${COMPLETE_SOURCE})
target_link_libraries(cldeplus-static mysqlclient)
target_link_libraries(cldeplus mysqlclient)

set_target_properties(cldeplus cldeplus-static PROPERTIES
        VERSION ${VERSION}
        SOVERSION ${VERSION}
)

if (APPLE)
    set_property(TARGET cldeplus PROPERTY PREFIX "lib")
    set_property(TARGET cldeplus PROPERTY SUFFIX ".so")
endif ()


# Installation
set(INSTALL_DIR "${EXTRA_DIR}")
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR}/${CMAKE_PROJECT_NAME}-${VERSION})
install(DIRECTORY Source/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
install(TARGETS cldeplus cldeplus-static
        LIBRARY DESTINATION ./
        ARCHIVE DESTINATION ./
)


# TARGET-LIBRARIES (Sub-directories)
add_subdirectory(Examples)
add_subdirectory(Test)