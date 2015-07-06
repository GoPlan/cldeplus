//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_JOIN_RIGHT_H
#define CLOUD_E_PLUS_SEGMENTATION_JOIN_RIGHT_H

#include "Left.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            class Right {

                Left left{};

            public:
                Right() = default;
                Right(const Right &) = default;
                Right(Right &&) = default;
                Right &operator=(const Right &) = default;
                Right &operator=(Right &&) = default;
                ~Right() = default;

                // Accessors
                const Foundation::SPtrColumnVector &getCLhsComparingColumns() const { return left.getCRhsComparingColumns(); }
                const Foundation::SPtrColumnVector &getCRhsComparingColumns() const { return left.getCLhsComparingColumns(); }
                const Segmentation::Transformation::SPtrEntityTransformer &getLhsCTransformer() const { return left.getRhsCTransformer(); }
                const Segmentation::Transformation::SPtrEntityTransformer &getRhsCTransformer() const { return left.getLhsCTransformer(); }

                Foundation::SPtrColumnVector &LhsComparingColumns() { return left.RhsComparingColumns(); }
                Foundation::SPtrColumnVector &RhsComparingColumns() { return left.LhsComparingColumns(); }
                Segmentation::Transformation::SPtrEntityTransformer &LhsTransformer() { return left.RhsTransformer(); }
                Segmentation::Transformation::SPtrEntityTransformer &RhsTransformer() { return left.LhsTransformer(); }

                // Locals
                Foundation::SPtrEntityProxySet JoinSet(const Foundation::SPtrEntityProxySet &lhsSet,
                                                       const Foundation::SPtrEntityProxySet &rhsSet) const;

                Foundation::SPtrEntityProxyVector JoinVector(const Foundation::SPtrEntityProxyVector &lhsVector,
                                                             const Foundation::SPtrEntityProxyVector &rhsVector) const;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_SEGMENTATION_JOIN_RIGHT_H
