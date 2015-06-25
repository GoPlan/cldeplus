//
// Created by LE, Duc Anh on 6/23/15.
//

#include <Foundation/Store/CellHelper.h>
#include <Foundation/Comparer/EntityProxyComparer.h>
#include "Inner.h"

namespace Cloude {
    namespace Foundation {

        SPtrEntityProxySet Segmentation::Helper::Inner::operator()(const JoinPhrase &lhsPhrase,
                                                                   const JoinPhrase &rhsPhrase) const {

            Comparer::EntityProxyComparer compare{lhsPhrase.getVectorComparingColumns(),
                                                  rhsPhrase.getVectorComparingColumns()};

            SPtrEntityProxySet setProxies;
            auto lhsIter = lhsPhrase.getSetProxies().cbegin();
            auto rhsIter = rhsPhrase.getSetProxies().cbegin();

            while (lhsIter != lhsPhrase.getSetProxies().cend()) {

                if (rhsIter == rhsPhrase.getSetProxies().cend())
                    break;

                while (compare(*lhsIter, *rhsIter).result == 0) {

                    auto proxy = std::make_shared<EntityProxy>();

                    for (auto &pairColumnNames : lhsPhrase.getVectorDisplayColumnPairs()) {

                        auto sptrCell = Store::CellHelper::CopySptrCell((*lhsIter)->getCell(pairColumnNames.first));
                        auto &sptrColumn = sptrCell->getColumn();

                        sptrColumn->setName(pairColumnNames.second);
                    }

                    for (auto &pairColumnNames : rhsPhrase.getVectorDisplayColumnPairs()) {

                        auto sptrCell = Store::CellHelper::CopySptrCell((*lhsIter)->getCell(pairColumnNames.first));
                        auto &sptrColumn = sptrCell->getColumn();

                        sptrColumn->setName(pairColumnNames.second);
                    }

                    setProxies.insert(proxy);

                    ++rhsIter;
                }

                ++lhsIter;
            }

            return setProxies;
        }
    }
}


