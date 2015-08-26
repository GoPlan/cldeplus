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
        Application/MapFactory.cpp Application/MapFactory.h)


# Library links search paths
link_directories(${GTEST}/lib)
link_directories(${CLDEPARSER})
link_directories(${EXTRA_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64/lib)


# TARGET-EXECUTABLE: cloud_e_plus
add_executable(cloud_e_plus_test main.cpp)
target_link_libraries(cloud_e_plus_test foundation segmentation relation configuration)
target_link_libraries(cloud_e_plus_test cldesqlitedriver cldemysqldriver)
target_link_libraries(cloud_e_plus_test apptest)
target_link_libraries(cloud_e_plus_test cldeparser-static gtest mysqlclient)
