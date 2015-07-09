//
// Created by LE, Duc Anh on 7/3/15.
//

#ifndef CLOUD_E_PLUS_RELATION_RELATIONMAP_H
#define CLOUD_E_PLUS_RELATION_RELATIONMAP_H

#include <unordered_map>

namespace Cloude {
    namespace Relation {

        using ColumnNamesMap = std::unordered_map<std::string, std::string>;

        class RelationMap {

        public:
            RelationMap() = default;
            RelationMap(const RelationMap &) = default;
            RelationMap(RelationMap &&) = default;
            RelationMap &operator=(const RelationMap &) = default;
            RelationMap &operator=(RelationMap &&) = default;
            virtual ~RelationMap() = default;
        };
    }
}


#endif //CLOUD_E_PLUS_RELATION_RELATIONMAP_H
