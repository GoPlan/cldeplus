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

#include "RelationMap.h"

namespace CLDEPlus {
    namespace Relation {

        void RelationMap::AddLink(string const &srcColumnName, Foundation::SPtrColumn const &dstColumn) {
            _columnsMap.push_back(std::make_pair(srcColumnName, dstColumn));
        }

        void RelationMap::AddLink(Foundation::SPtrColumn const &srcColumn, Foundation::SPtrColumn const &dstColumn) {
            AddLink(srcColumn->getName(), dstColumn);
        }

        Foundation::Query::SPtrCriteria RelationMap::Generate(Foundation::Entity const &entity) const {

            using CmpFactory = Foundation::Query::ComparativeFactory;

            Foundation::Query::SPtrCriteria criteria;

            for (auto &link : _columnsMap) {

                auto &srcCell = entity.getCell(link.first);
                auto &dstColumn = link.second;
                auto current = CmpFactory::CreateEQ(dstColumn, srcCell->getValue());

                if (!criteria) {
                    criteria = current;
                }
                else {
                    auto tmp = criteria;
                    criteria = CmpFactory::CreateAND(tmp, current);
                }
            }

            return criteria;
        }
    }
}

