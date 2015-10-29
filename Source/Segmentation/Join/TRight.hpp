//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_SEGMENTATION_JOIN_RIGHT_H
#define CLDEPLUS_SEGMENTATION_JOIN_RIGHT_H

#include "TLeft.hpp"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Join {

            template<class TContainer = Foundation::SPtrEntityProxyVector>
            class TRight {

                TLeft<TContainer> left{};

            public:
                TRight() = default;
                TRight(const TRight &) = default;
                TRight(TRight &&) = default;
                TRight &operator=(const TRight &) = default;
                TRight &operator=(TRight &&) = default;
                ~TRight() = default;

                // Accessors
                const Foundation::SPtrColumnVector &getCLhsComparingColumns() const { return left.getCRhsComparingColumns(); }
                const Foundation::SPtrColumnVector &getCRhsComparingColumns() const { return left.getCLhsComparingColumns(); }
                const Segmentation::Transformation::SPtrEntityTransformer &getLhsCTransformer() const { return left.getRhsCTransformer(); }
                const Segmentation::Transformation::SPtrEntityTransformer &getRhsCTransformer() const { return left.getLhsCTransformer(); }

                // Mutators
                Foundation::SPtrColumnVector &LhsComparingColumns() { return left.RhsComparingColumns(); }
                Foundation::SPtrColumnVector &RhsComparingColumns() { return left.LhsComparingColumns(); }
                Segmentation::Transformation::SPtrEntityTransformer &LhsTransformer() { return left.RhsTransformer(); }
                Segmentation::Transformation::SPtrEntityTransformer &RhsTransformer() { return left.LhsTransformer(); }

                // Locals
                TContainer Join(const TContainer &lhsContainer, const TContainer &rhsContainer) const {
                    return left.Join(rhsContainer, lhsContainer);
                }
            };

            using Right = TRight<>;
        }
    }
}

#endif //CLDEPLUS_SEGMENTATION_JOIN_RIGHT_H
