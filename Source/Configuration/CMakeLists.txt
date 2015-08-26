# Configuration


include_directories(${CLDEPARSER}/include)
add_library(configuration STATIC
        JsonConfigurator.cpp
        JsonConfigurator.h
)

