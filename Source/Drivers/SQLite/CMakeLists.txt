# Drivers - SQLite


add_library(cldesqlitedriver STATIC
        SQLiteSourceDriver.cpp
        SQLiteSourceDriver.h
        SQLiteSourceException.cpp
        SQLiteSourceException.h
        SQLiteSourceHelper.cpp
        SQLiteSourceHelper.h
        Amalgamation/sqlite3.h
        Amalgamation/sqlite3ext.h
        Amalgamation/sqlite3.c
)