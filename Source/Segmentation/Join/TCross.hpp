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

#ifndef CLDEPLUS_SEGMENTATION_JOIN_CROSS_H
#define CLDEPLUS_SEGMENTATION_JOIN_CROSS_H

#include "../../Foundation/EntityProxy.h"
#include "../Transformation/EntityTransformer.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Join {

            template<class TContainer = Foundation::SPtrEntityProxyVector>
            class TCross {

                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                TCross() : _sptrRhsTransformer{new Transformation::EntityTransformer{}},
                           _sptrLhsTransformer{new Transformation::EntityTransformer{}} { };

                TCross(const TCross &) = default;
                TCross(TCross &&) = default;
                TCross &operator=(const TCross &) = default;
                TCross &operator=(TCross &&) = default;
                ~TCross() = default;

                // Accessors
                const Segmentation::Transformation::SPtrEntityTransformer &getLhsCTransformer() const { return _sptrLhsTransformer; }
                const Segmentation::Transformation::SPtrEntityTransformer &getRhsCTransformer() const { return _sptrRhsTransformer; }

                // Mutators
                Segmentation::Transformation::SPtrEntityTransformer &LhsTransformer() { return _sptrLhsTransformer; }
                Segmentation::Transformation::SPtrEntityTransformer &RhsTransformer() { return _sptrRhsTransformer; }

                // Locals
                TContainer Join(const TContainer &lhsContainer, const TContainer &rhsContainer) const {

                    TContainer proxiesContainer;

                    auto lhsCurrent = lhsContainer.begin();
                    auto rhsCurrent = rhsContainer.begin();

                    auto lhsEnd = lhsContainer.end();
                    auto rhsEnd = rhsContainer.end();

                    while (lhsCurrent != lhsEnd) {

                        while (rhsCurrent != rhsEnd) {

                            Foundation::SPtrEntityProxy proxy = cldeplus_make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            _sptrRhsTransformer->Transform(*rhsCurrent, proxy);

                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++rhsCurrent;
                        }

                        rhsCurrent = rhsContainer.begin();
                        ++lhsCurrent;
                    }

                    return proxiesContainer;
                }
            };

            using Cross = TCross<>;
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_JOIN_CROSS_H
