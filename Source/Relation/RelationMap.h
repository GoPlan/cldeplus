//
// Created by LE, Duc Anh on 7/3/15.
//

#ifndef CLDEPLUS_RELATION_RELATIONMAP_H
#define CLDEPLUS_RELATION_RELATIONMAP_H

#include "../Foundation/Query/Query.h"
#include "../Foundation/Entity.h"

namespace CLDEPlus {
    namespace Relation {

        using LinkColumn = pair<string, Foundation::SPtrColumn>;
        using LinkColumnsMap = vector<LinkColumn>;

        class RelationMap {

            LinkColumnsMap _columnsMap;

        public:
            RelationMap() = default;
            RelationMap(RelationMap const &) = default;
            RelationMap(RelationMap &&) = default;
            RelationMap &operator=(RelationMap const &) = default;
            RelationMap &operator=(RelationMap &&) = default;
            virtual ~RelationMap() = default;

            // Locals
            void AddLink(string const &srcColumnName, Foundation::SPtrColumn const &dstColumn);
            void AddLink(Foundation::SPtrColumn const &srcColumn, Foundation::SPtrColumn const &dstColumn);
            Foundation::Query::SPtrCriteria Generate(Foundation::Entity const &entity) const;
        };
    }
}


#endif //CLDEPLUS_RELATION_RELATIONMAP_H
