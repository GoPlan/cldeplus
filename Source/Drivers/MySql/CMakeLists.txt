# Drivers - MySql


include_directories(${EXTRA_DIR}/mysql-connector-c-6.1.6-osx10.8-x86_64/include)
add_library(cldemysqldriver STATIC
        MySqlSourceDriver.h
        MySqlSourceDriver.cpp
        MySqlSourceException.h
        MySqlSourceException.cpp
        MySqlSourceFactory.cpp
        MySqlSourceFactory.h
        MySqlHelper.cpp
        MySqlHelper.h
        Data/MySqlDate.cpp
        Data/MySqlDate.h
        Data/MySqlTime.cpp
        Data/MySqlTime.h
        Data/MySqlDateTime.cpp
        Data/MySqlDateTime.h
        Data/MySqlDateTimeImpl.cpp
        Data/MySqlDateTimeImpl.h
)


