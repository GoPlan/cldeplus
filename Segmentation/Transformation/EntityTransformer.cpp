//
// Created by LE, Duc Anh on 6/30/15.
//

#include "EntityTransformer.h"

namespace Cloude {
    namespace Segmentation {

        Foundation::SPtrEntityProxy Transformation::EntityTransformer::Transform(
                const Foundation::SPtrEntityProxy &lhsProxy,
                const Foundation::SPtrEntityProxy &rhsProxy) const {

            Foundation::SPtrEntityProxy proxy;

            for (auto &pairCellMap : _lhsCellTransformerMap) {
                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;
                Foundation::SPtrCell sptrNewCell = sptrCellTransfomer->Transform(lhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            for (auto &pairCellMap : _rhsCellTransformerMap) {
                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;
                Foundation::SPtrCell sptrNewCell = sptrCellTransfomer->Transform(rhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            return proxy;
        }

        Foundation::SPtrEntityProxy Transformation::EntityTransformer::TransformLeftOnly(
                const Foundation::SPtrEntityProxy &lhsProxy) const {

            Foundation::SPtrEntityProxy proxy;

            for (auto &pairCellMap : _lhsCellTransformerMap) {
                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;
                Foundation::SPtrCell sptrNewCell = sptrCellTransfomer->Transform(lhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            return proxy;
        }

        Foundation::SPtrEntityProxy Transformation::EntityTransformer::TransformRightOnly(
                const Foundation::SPtrEntityProxy &rhsProxy) const {

            Foundation::SPtrEntityProxy proxy;

            for (auto &pairCellMap : _rhsCellTransformerMap) {
                auto &srcColumnName = pairCellMap.first;
                auto &sptrCellTransfomer = pairCellMap.second;
                Foundation::SPtrCell sptrNewCell = sptrCellTransfomer->Transform(rhsProxy->getCell(srcColumnName));
                proxy->setCell(sptrNewCell);
            }

            return proxy;
        }
    }
}


