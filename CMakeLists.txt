cmake_minimum_required(VERSION 3.2)
project(CldePlus)

# Build variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VERSION 0.8.0)
set(STORAGE "~/Devel")
set(EXTRA_DIR ${STORAGE}/Extra)

add_subdirectory(CldePlus)

# INSTALLATION
#set(INSTALL_DIR "${EXTRA_DIR}")
#set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR}/${CMAKE_PROJECT_NAME}-${VERSION})
#install(DIRECTORY CldePlus/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
#install(DIRECTORY CldePlus/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.hpp")
#install(TARGETS CldePlus cldeplus-static
#        LIBRARY DESTINATION ./
#        ARCHIVE DESTINATION ./
#)

# TARGET-LIBRARIES (Sub-directories)
#add_subdirectory(Examples)
#add_subdirectory(Tests)