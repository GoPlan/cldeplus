
# FOUNDATION SOURCE
set(FOUNDATION_SOURCE
        Cell.cpp
        Column.cpp
        Entity.cpp
        EntityMap.cpp
        EntityProxy.cpp
        EntityQuery.cpp
        EntitySourceDriver.cpp
        EntityStore.cpp
        Identity.cpp)


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