//
// Created by LE, Duc Anh on 7/3/15.
//

#include "RelationMap.h"

namespace CLDEPlus {
    namespace Relation {

        void RelationMap::AddLink(const string &srcColumnName, Foundation::SPtrColumn const &dstColumn) {
            _columnsMap.push_back(std::make_pair(srcColumnName, dstColumn));
        }


        void RelationMap::AddLink(const Foundation::SPtrColumn &srcColumn, Foundation::SPtrColumn const &dstColumn) {
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

