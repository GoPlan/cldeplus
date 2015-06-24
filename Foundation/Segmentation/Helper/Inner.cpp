//
// Created by LE, Duc Anh on 6/23/15.
//

#include "Foundation/Comparer/EntityProxyComparer.h"
#include "Inner.h"

namespace Cloude {
    namespace Foundation {

        SPtrEntityProxySet Segmentation::Helper::Inner::operator()(const JoinPhrase &lhsPhrase,
                                                                   const JoinPhrase &rhsPhrase) const {

            SPtrColumnVector lhsComparingColumns;
            SPtrColumnVector rhsComparingColumns;

            for (auto &pairColumnName : lhsPhrase.getVectorComparingColumns()) {

            }


            Comparer::EntityProxyComparer compare{lhsComparingColumns, rhsComparingColumns};

            SPtrEntityProxySet setProxies;
            auto lhsIter = lhsPhrase.getSetProxies().cbegin();
            auto rhsIter = rhsPhrase.getSetProxies().cbegin();

            while (lhsIter != lhsPhrase.getSetProxies().cend()) {

                if (rhsIter == rhsPhrase.getSetProxies().cend())
                    break;

                while (compare(*lhsIter, *rhsIter)) {

                    auto proxy = std::make_shared<EntityProxy>();

                    for (auto &columnPair : lhsPhrase.getVectorDisplayColumns()) {

                        auto sptrCell = (*lhsIter)->getCell(columnPair.first);
                        auto &sptrColumn = sptrCell->getColumn();

                        sptrColumn->setName(columnPair.second);
                    }

                    for (auto &columnPair : rhsPhrase.getVectorDisplayColumns()) {

                        auto sptrCell = (*rhsIter)->getCell(columnPair.first);
                        auto &sptrColumn = sptrCell->getColumn();

                        sptrColumn->setName(columnPair.second);
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


