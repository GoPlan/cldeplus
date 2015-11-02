//
// Created by LE, Duc Anh on 6/30/15.
//

#include <stdexcept>
#include "../Exception/TransformationException.h"
#include "EntityTransformer.h"

namespace CLDEPlus {
    namespace Segmentation {

        void Transformation::EntityTransformer::AddCellTransformer(
                const string &columnName,
                const Transformation::CellTransformer &cellTransformer) {
            _mapCellTransformers.insert(std::make_pair(columnName, cellTransformer));
        }

        void Transformation::EntityTransformer::Transform(
                const Foundation::SPtrEntityProxy &srcProxy,
                Foundation::SPtrEntityProxy &dstProxy) const {

            if (!srcProxy) {
                string msg{"srcProxy is either invalid or a nullptr"};
                throw Exception::TransformationException{msg};
            }

            if (!dstProxy) {
                string msg{"dstProxy is either invalid or a nullptr"};
                throw Exception::TransformationException{msg};
            }

            for (auto &pairCellMap : _mapCellTransformers) {
                auto &srcColumnName = pairCellMap.first;
                auto &cellTransformer = pairCellMap.second;
                Foundation::SPtrCell sptrNewCell = cellTransformer.Transform(srcProxy->getCell(srcColumnName));
                dstProxy->setCell(sptrNewCell);
            }
        }

        Transformation::UPtrEntityTransformer Transformation::CreateEntityTransformerInstance() {
            return unique_ptr<EntityTransformer>(new EntityTransformer());
        }
    }
}


