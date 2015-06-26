//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/Store/Comparer/DataRecordCompare.h>
#include "Cross.h"

namespace Cloude {
    namespace Foundation {

        SPtrEntityProxySet Segmentation::Helper::Cross::operator()(const JoinPhrase &lhsPhrase,
                                                                   const JoinPhrase &rhsPhrase) const {

            Store::Comparer::DataRecordCompare<> equal{lhsPhrase.getVectorComparingColumns(),
                                                     rhsPhrase.getVectorComparingColumns()};

            SPtrEntityProxySet setProxies;
            auto lhsIter = lhsPhrase.getSetProxies().cbegin();
            auto rhsIter = rhsPhrase.getSetProxies().cbegin();

            while (lhsIter != lhsPhrase.getSetProxies().cend() || rhsIter != rhsPhrase.getSetProxies().cend()) {

                SPtrEntityProxyVector vtorSkippedProxies;
                SPtrEntityProxyVector vtorMatchedProxies;

                while (equal(**lhsIter, **rhsIter)) {

                    auto proxy = std::make_shared<EntityProxy>();

                    for (auto &pairColumnNames : lhsPhrase.getVectorDisplayColumnPairs()) {

                        auto sptrCell = Store::Helper::CellHelper::CopySptrCell((*lhsIter)->getCell(pairColumnNames.first));
                        auto &sptrColumn = sptrCell->getColumn();

                        sptrColumn->setName(pairColumnNames.second);
                    }

                    for (auto &pairColumnNames : rhsPhrase.getVectorDisplayColumnPairs()) {

                        auto sptrCell =
                                Store::Helper::CellHelper::CopySptrCell((*lhsIter)->getCell(pairColumnNames.first));
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


