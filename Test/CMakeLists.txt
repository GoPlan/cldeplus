# AppTest
include_directories(${GTEST}/include)
add_library(apptest STATIC
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
        Application/MapFactory.cpp
        Application/MapFactory.h
)


# Library links search paths
link_directories(${GTEST}/lib)
link_directories(${CLDEPARSER})
link_directories(${EXTRA_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64/lib)


# TARGET-EXECUTABLE: cloud_e_plus
add_executable(cldeplus-test main.cpp)
target_link_libraries(cldeplus-test apptest)
target_link_libraries(cldeplus-test cldeplus-static)
target_link_libraries(cldeplus-test cldeparser-static gtest)


# COPY Examples
set(EXAMPLE "example01.db")
add_custom_command(TARGET cldeplus-test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE}
        $<TARGET_FILE_DIR:cldeplus-test>/${EXAMPLE}
)


# Valgrind cldeparser-apptest
add_custom_target(cldeplus-valgrind ALL
        COMMAND valgrind -v --leak-check=summary --show-leak-kinds=all --track-origins=yes ./cldeplus-test
        COMMENT cldeplus-test
)

add_dependencies(cldeplus-valgrind cldeplus-test)
