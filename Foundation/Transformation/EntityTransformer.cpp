//
// Created by LE, Duc Anh on 6/30/15.
//

#include "EntityTransformer.h"

namespace Cloude {
    namespace Foundation {

        Transformation::EntityTransformer::EntityTransformer(const Segmentation::JoinPhrase &lhsPhrase,
                                                             const Segmentation::JoinPhrase &rhsPhrase)
                : _lhsPhrase(lhsPhrase), _rhsPhrase(rhsPhrase) {
            //
        }

        SPtrEntityProxy Transformation::EntityTransformer::Transform(const SPtrEntityProxy &lhsProxy,
                                                                     const SPtrEntityProxy &rhsProxy) const {

            SPtrEntityProxy proxy;

            for (auto &pairCellMap : _lhsPhrase.CDisplayColumnsMap()) {

                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;

                SPtrCell sptrNewCell = sptrCellTransfomer->Transform(lhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            for (auto &pairCellMap : _rhsPhrase.CDisplayColumnsMap()) {

                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;

                SPtrCell sptrNewCell = sptrCellTransfomer->Transform(rhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            return proxy;
        }
    }
}


