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
