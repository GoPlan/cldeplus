
# GTEST
set(GTEST "${CMAKE_SOURCE_DIR}/Extra/gtest-1.7.0")
include_directories(${GTEST}/include)
link_directories(${GTEST}/lib)

# MYSQL
include_directories(${MYSQL_DIR}/include)
link_directories(${MYSQL_DIR}/lib)

# CLDEPARSER
include_directories(${CLDEPARSER_DIR}/include)
link_directories(${CLDEPARSER_DIR})

# TARGET-EXECUTABLE: cloud_e_plus
add_executable(cldeplus-test main.cpp
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
        Store/Preparation/ProductSQLiteStore.cpp
        Store/Preparation/ProductSQLiteStore.h
        Store/Preparation/PreOrderMySqlStore.cpp
        Store/Preparation/PreOrderMySqlStore.h
        Store/Preparation/EnquiryMySqlStore.cpp
        Store/Preparation/EnquiryMySqlStore.h
        Application/MapFactory.cpp
        Application/MapFactory.h
        Segmentation/Segmentation.cpp
        Segmentation/Transformation.cpp
        Store/SQLiteStore.cpp
        Store/MySqlStore00.cpp
        Store/MySqlStore01.cpp
        Store/MySqlStore02.cpp
        Store/MySqlStore00.cpp
        Store/MySqlStore01.cpp
        Store/MySqlStore02.cpp
        Relation/NamedEntity01.cpp
        Relation/NamedEntity02.cpp
        Type/ValueComparison.cpp
        Type/CreateValue.cpp)

target_link_libraries(cldeplus-test cldeplus-static)
target_link_libraries(cldeplus-test cldeparser-static gtest)

# COPY Examples
set(EXAMPLE "example01.db")
add_custom_command(TARGET cldeplus-test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE}
        $<TARGET_FILE_DIR:cldeplus-test>/${EXAMPLE})

# TESTs
enable_testing()
add_test(NAME cldeplus-valgrind COMMAND valgrind -v --leak-check=summary --show-leak-kinds=all --track-origins=yes ./cldeplus-test)


