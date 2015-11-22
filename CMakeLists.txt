cmake_minimum_required(VERSION 3.2)
project(cldeplus)

# Build variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VERSION 0.7.0)
set(STORAGE "~/Devel")
set(EXTRA_DIR ${STORAGE}/Extra)
set(MYSQL_DIR ${EXTRA_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64)
set(CLDEPARSER_DIR "${EXTRA_DIR}/cldeparser-1.0.0")
set(GTEST_DIR "${EXTRA_DIR}/gtest-1.7.0")

# MYSQL
include_directories(${MYSQL_DIR}/include)
link_directories(${MYSQL_DIR}/lib)

# CLDEPARSER
link_directories(${CLDEPARSER_DIR})
include_directories(${CLDEPARSER_DIR}/include)

# GTEST
include_directories(${GTEST_DIR}/include)
link_directories(${GTEST_DIR}/build)

# SOURCE - Core
file(GLOB_RECURSE FOUNDATION_SOURCE Source/Foundation/*.cpp Source/Foundation/*.h Source/Foundation/*.hpp)
file(GLOB_RECURSE RELATION_SOURCE Source/Relation/*.cpp Source/Relation/*.h Source/Relation/*.hpp)
file(GLOB_RECURSE SEGMENTATION_SOURCE Source/Segmentation/*.cpp Source/Segmentation/*.h Source/Segmentation/*.hpp)

# SOURCE - Drivers
file(GLOB_RECURSE DRIVERS_MYSQL Source/Drivers/MySql/*.cpp Source/Drivers/MySql/*.h)
file(GLOB_RECURSE DRIVERS_SQLITE Source/Drivers/SQLite/*.cpp Source/Drivers/SQLite/*.h Source/Drivers/SQLite/Amalgamation/*)

# COMPLETE_SOURCE
set(COMPLETE_SOURCE
        Source/cldeplus.h
        Source/portable.h
        ${FOUNDATION_SOURCE}
        ${RELATION_SOURCE}
        ${SEGMENTATION_SOURCE}
        ${DRIVERS_SQLITE}
        ${DRIVERS_MYSQL})

# MAIN TARGETS
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

# INSTALLATION
set(INSTALL_DIR "${EXTRA_DIR}")
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR}/${CMAKE_PROJECT_NAME}-${VERSION})
install(DIRECTORY Source/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
install(DIRECTORY Source/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.hpp")
install(TARGETS cldeplus cldeplus-static
        LIBRARY DESTINATION ./
        ARCHIVE DESTINATION ./
)

# TARGET-LIBRARIES (Sub-directories)
add_subdirectory(Examples)
add_subdirectory(Test)