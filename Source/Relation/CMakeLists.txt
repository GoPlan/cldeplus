# Relation


add_library(relation STATIC
        Relation.h
        NamedEntityLoader.cpp
        NamedEntityLoader.h
        RelationMap.cpp
        RelationMap.h
        Link.cpp
        Link.h
        LinkToOne.cpp
        LinkToOne.h
        LinkToMany.cpp
        LinkToMany.h
        NamedEntityStore.cpp
        NamedEntityStore.h
        MultiCellsObject.cpp
        MultiCellsObject.h
        Exception/NamedEntityStoreException.cpp
        Exception/NamedEntityStoreException.h
)