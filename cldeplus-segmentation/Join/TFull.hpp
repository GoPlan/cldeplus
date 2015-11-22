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

#ifndef CLDEPLUS_SEGMENTATION_JOIN_FULL_H
#define CLDEPLUS_SEGMENTATION_JOIN_FULL_H

#include "../../Foundation/Store/Comparer/Compare.h"
#include "../../Foundation/Store/Comparer/Greater.h"
#include "../../Foundation/Store/Helper/CellHelper.h"
#include "../../Segmentation/Transformation/EntityTransformer.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Join {

            template<class TContainer = Foundation::SPtrEntityProxyVector>
            class TFull {

                Foundation::SPtrColumnVector _lhsComparingColumns{};
                Foundation::SPtrColumnVector _rhsComparingColumns{};
                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                TFull() : _sptrLhsTransformer{new Transformation::EntityTransformer{}},
                          _sptrRhsTransformer{new Transformation::EntityTransformer{}} { };

                TFull(const TFull &) = default;
                TFull(TFull &&) = default;
                TFull &operator=(const TFull &) = default;
                TFull &operator=(TFull &&) = default;
                virtual ~TFull() = default;

                // Accessors
                const Foundation::SPtrColumnVector &getCLhsComparingColumns() const { return _lhsComparingColumns; }
                const Foundation::SPtrColumnVector &getCRhsComparingColumns() const { return _rhsComparingColumns; }
                const Segmentation::Transformation::SPtrEntityTransformer &getLhsCTransformer() const { return _sptrLhsTransformer; }
                const Segmentation::Transformation::SPtrEntityTransformer &getRhsCTransformer() const { return _sptrRhsTransformer; }

                // Mutators
                Foundation::SPtrColumnVector &LhsComparingColumns() { return _lhsComparingColumns; }
                Foundation::SPtrColumnVector &RhsComparingColumns() { return _rhsComparingColumns; }
                Segmentation::Transformation::SPtrEntityTransformer &LhsTransformer() { return _sptrLhsTransformer; }
                Segmentation::Transformation::SPtrEntityTransformer &RhsTransformer() { return _sptrRhsTransformer; }

                // Locals
                TContainer Join(const TContainer &lhsContainer, const TContainer &rhsContainer) const{

                    using CellHelper = Foundation::Store::Helper::CellHelper;
                    using DataRecordLess = Foundation::Store::Comparer::Less;
                    using DataRecordGreater = Foundation::Store::Comparer::Greater;
                    using DataRecordCompare = Foundation::Store::Comparer::Compare<>;

                    DataRecordCompare EQ{_lhsComparingColumns, _lhsComparingColumns};
                    DataRecordLess LT{_lhsComparingColumns, _rhsComparingColumns};
                    DataRecordGreater GT{_lhsComparingColumns, _rhsComparingColumns};

                    TContainer proxiesContainer;
                    auto lhsCurrent = lhsContainer.cbegin();
                    auto rhsCurrent = rhsContainer.cbegin();
                    auto lhsEnd = lhsContainer.cend();
                    auto rhsEnd = rhsContainer.cend();


                    while (lhsCurrent != lhsEnd || rhsCurrent != rhsEnd) {

                        if (lhsCurrent == lhsEnd) {
                            Foundation::SPtrEntityProxy proxy = cldeplus_make_shared<Foundation::EntityProxy>();
                            _sptrRhsTransformer->Transform(*rhsCurrent, proxy);
                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++rhsCurrent;
                            break;
                        }

                        if (rhsCurrent == rhsEnd) {
                            Foundation::SPtrEntityProxy proxy = cldeplus_make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++lhsCurrent;
                            continue;
                        }

                        if (lhsCurrent != lhsEnd && LT(*lhsCurrent, *rhsCurrent)) {
                            Foundation::SPtrEntityProxy proxy = cldeplus_make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++lhsCurrent;
                            continue;
                        }
                        else if (rhsCurrent != rhsEnd && GT(*lhsCurrent, *rhsCurrent)) {
                            Foundation::SPtrEntityProxy proxy = cldeplus_make_shared<Foundation::EntityProxy>();
                            _sptrRhsTransformer->Transform(*rhsCurrent, proxy);
                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++rhsCurrent;
                            continue;
                        }
                        else {

                            auto rhsTmp = rhsCurrent;
                            auto lhsTmp = lhsCurrent;

                            while (rhsCurrent != rhsEnd && !LT(*lhsCurrent, *rhsCurrent)) {
                                Foundation::SPtrEntityProxy proxy = cldeplus_make_shared<Foundation::EntityProxy>();
                                _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                                _sptrRhsTransformer->Transform(*rhsCurrent, proxy);
                                proxiesContainer.insert(proxiesContainer.cend(), proxy);
                                ++rhsCurrent;
                            }

                            ++lhsCurrent;

                            if (lhsCurrent != lhsEnd && EQ(*lhsTmp, *(lhsCurrent)))
                                rhsCurrent = rhsTmp;
                        }
                    }

                    return proxiesContainer;
                };
            };

            using Full = TFull<>;
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_JOIN_FULL_H
