

# FOUNDATION SOURCE
set(FOUNDATION_SOURCE
        Exception.cpp
        Exceptions/NonSupportedFunctionException.cpp
        Exceptions/NotImplementedException.cpp
        Value.cpp
        ValueFactory.cpp
        Primitive.cpp
        Data/DataTypeException.cpp
        Data/NumericValue.cpp
        Data/CharacterValue.cpp
        Data/TimeBasedValue.cpp
        Data/Type/Boolean.cpp
        Data/Type/Byte.cpp
        Data/Type/Date.cpp
        Data/Type/DateTime.cpp
        Data/Type/Double.cpp
        Data/Type/Float.cpp
        Data/Type/Int16.cpp
        Data/Type/Int32.cpp
        Data/Type/Int64.cpp
        Data/Type/UInt16.cpp
        Data/Type/UInt32.cpp
        Data/Type/UInt64.cpp
        Data/Type/String.cpp
        Data/Type/Text.cpp
        Data/Type/Time.cpp
        Data/Type/UInt16.cpp
        Data/Type/UInt32.cpp
        Data/Type/UInt64.cpp
        Data/Type/VarChar.cpp
        Data/Helper/TimeBasedHelper.cpp
        Data/Helper/ValueEnumsHelper.cpp
        #        Cell.cpp
        EntityColumn.cpp
        #        Entity.cpp
        #        EntityMap.cpp
        #        EntityProxy.cpp
        #        EntityQuery.cpp
        #        EntitySourceDriver.cpp
        #        EntityStore.cpp
        #        Identity.cpp
        )


# MAIN TARGETS
add_library(cldeplus SHARED ${FOUNDATION_SOURCE})
add_library(cldeplus-static STATIC ${FOUNDATION_SOURCE})

set_target_properties(cldeplus cldeplus-static PROPERTIES
        VERSION ${VERSION}
        SOVERSION ${VERSION})

if (APPLE)
    set_property(TARGET cldeplus PROPERTY PREFIX "lib")
    set_property(TARGET cldeplus PROPERTY SUFFIX ".so")
endif ()