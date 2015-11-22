/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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
