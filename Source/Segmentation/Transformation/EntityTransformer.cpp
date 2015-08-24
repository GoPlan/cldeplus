//
// Created by LE, Duc Anh on 6/30/15.
//

#include <stdexcept>
#include <Segmentation/Exception/TransformationException.h>
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

            if (!srcProxy) {
                std::string msg{"srcProxy is either invalid or a nullptr"};
                throw Exception::TransformationException{msg};
            }

            if (!dstProxy) {
                std::string msg{"dstProxy is either invalid or a nullptr"};
                throw Exception::TransformationException{msg};
            }

            for (auto &pairCellMap : _mapCellTransformers) {
                auto &srcColumnName = pairCellMap.first;
                auto &cellTransformer = pairCellMap.second;
                Foundation::SPtrCell sptrNewCell = cellTransformer.Transform(srcProxy->getCell(srcColumnName));
                dstProxy->setCell(sptrNewCell);
            }
        }

        Transformation::SPtrEntityTransformer Transformation::CreateEntityTransformer() {
            return std::make_shared<EntityTransformer>();
        }
    }
}


