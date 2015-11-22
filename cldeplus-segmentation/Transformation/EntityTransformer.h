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

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H

#include "../../Foundation/EntityProxy.h"
#include "CellTransformer.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {

            /// EntityTransformer:
            /// Transform an entity into new entity based on a map of transformers.
            /// Only cell with names provided in the map are copied into the new entity.
            ///
            class EntityTransformer {

                Transformation::CellTransformerMap _mapCellTransformers;

            public:
                EntityTransformer() = default;
                EntityTransformer(const EntityTransformer &) = default;
                EntityTransformer(EntityTransformer &&) = default;
                EntityTransformer &operator=(const EntityTransformer &) = default;
                EntityTransformer &operator=(EntityTransformer &&) = default;
                ~EntityTransformer() = default;

                // Accessors
                Transformation::CellTransformerMap &CellTransformerMap() { return _mapCellTransformers; };

                // Mutators
                void AddCellTransformer(string const &columnName, CellTransformer const &cellTransformer);

                // Locals
                void Transform(Foundation::SPtrEntityProxy const &srcProxy, Foundation::SPtrEntityProxy &dstProxy) const;
            };

            using UPtrEntityTransformer = unique_ptr<EntityTransformer>;
            using SPtrEntityTransformer = shared_ptr<EntityTransformer>;

            UPtrEntityTransformer CreateEntityTransformerInstance();
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H
