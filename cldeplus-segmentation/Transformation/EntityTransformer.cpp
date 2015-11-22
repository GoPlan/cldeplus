/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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
            return cldeplus_make_unique<EntityTransformer>();
        }
    }
}


