//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H

#include "../../Foundation/EntityProxy.h"
#include "CellTransformer.h"

namespace Cloude {
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
                void AddCellTransformer(const std::string &columnName, const CellTransformer &cellTransformer);
                
                // Locals
                void Transform(const Foundation::SPtrEntityProxy &srcProxy, Foundation::SPtrEntityProxy &dstProxy) const;
            };

            using SPtrEntityTransformer = std::shared_ptr<EntityTransformer>;

            SPtrEntityTransformer CreateEntityTransformer();
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_ENTITYTRANSFORMER_H