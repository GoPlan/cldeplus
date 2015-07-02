//
// Created by LE, Duc Anh on 6/30/15.
//

#include <stdexcept>
#include "EntityTransformer.h"

namespace Cloude {
    namespace Segmentation {

        void Transformation::EntityTransformer::AddCellTransformer(
                const std::string &columnName,
                const Transformation::CellTransformer &cellTransformer) {
            _mapCellTransformers.insert(std::make_pair(columnName, cellTransformer));
        }

        void Transformation::EntityTransformer::Transform(
                const Foundation::SPtrEntityProxy &srcProxy,
                Foundation::SPtrEntityProxy &dstProxy) const {

            if (!srcProxy)
                throw std::invalid_argument{"srcProxy is either invalid or a nullptr"};

            if (!dstProxy)
                throw std::invalid_argument{"dstProxy is either invalid or a nullptr"};

            for (auto &pairCellMap : _mapCellTransformers) {
                auto &srcColumnName = pairCellMap.first;
                auto &cellTransformer = pairCellMap.second;
                Foundation::SPtrCell sptrNewCell = cellTransformer.Transform(srcProxy->getCell(srcColumnName));
                dstProxy->setCell(sptrNewCell);
            }
        }
    }
}


