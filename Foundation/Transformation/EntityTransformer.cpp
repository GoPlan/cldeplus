//
// Created by LE, Duc Anh on 6/30/15.
//

#include "EntityTransformer.h"

namespace Cloude {
    namespace Foundation {

        SPtrEntityProxy Transformation::EntityTransformer::Transform(const SPtrEntityProxy &lhsProxy,
                                                                     const SPtrEntityProxy &rhsProxy) const {

            SPtrEntityProxy proxy;

            for (auto &pairCellMap : _lhsCellTransformerMap) {

                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;

                SPtrCell sptrNewCell = sptrCellTransfomer->Transform(lhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            for (auto &pairCellMap : _rhsCellTransformerMap) {

                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;

                SPtrCell sptrNewCell = sptrCellTransfomer->Transform(rhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            return proxy;
        }

        SPtrEntityProxy Transformation::EntityTransformer::TransformLeftOnly(const SPtrEntityProxy &lhsProxy) const {

            SPtrEntityProxy proxy;

            for (auto &pairCellMap : _lhsCellTransformerMap) {

                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;

                SPtrCell sptrNewCell = sptrCellTransfomer->Transform(lhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            return proxy;
        }

        SPtrEntityProxy Transformation::EntityTransformer::TransformRightOnly(const SPtrEntityProxy &rhsProxy) const {

            SPtrEntityProxy proxy;

            for (auto &pairCellMap : _rhsCellTransformerMap) {

                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;

                SPtrCell sptrNewCell = sptrCellTransfomer->Transform(rhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            return proxy;
        }
    }
}


