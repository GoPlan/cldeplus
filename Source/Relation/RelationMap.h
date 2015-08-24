//
// Created by LE, Duc Anh on 7/3/15.
//

#ifndef CLOUD_E_PLUS_RELATION_RELATIONMAP_H
#define CLOUD_E_PLUS_RELATION_RELATIONMAP_H

#include "../Foundation/Query/Query.h"
#include "../Foundation/Entity.h"

namespace Cloude {
    namespace Relation {

        using LinkColumn = std::pair<std::string, Foundation::SPtrColumn>;
        using LinkColumnsMap = std::vector<LinkColumn>;

        class RelationMap {

            LinkColumnsMap _columnsMap;

        public:
            RelationMap() = default;
            RelationMap(const RelationMap &) = default;
            RelationMap(RelationMap &&) = default;
            RelationMap &operator=(const RelationMap &) = default;
            RelationMap &operator=(RelationMap &&) = default;
            virtual ~RelationMap() = default;

            // Locals
            void AddLink(const std::string& srcColumnName, const Foundation::SPtrColumn& dstColumn);
            void AddLink(const Foundation::SPtrColumn& srcColumn, const Foundation::SPtrColumn& dstColumn);
            Foundation::Query::SPtrCriteria Generate(const Foundation::Entity &entity) const;
        };
    }
}


#endif //CLOUD_E_PLUS_RELATION_RELATIONMAP_H
