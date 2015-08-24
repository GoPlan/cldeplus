//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_JOIN_LEFT_H
#define CLOUD_E_PLUS_SEGMENTATION_JOIN_LEFT_H

#include "../../Foundation/Store/Comparer/Compare.h"
#include "../../Foundation/Store/Comparer/Greater.h"
#include "../../Foundation/Store/Helper/CellHelper.h"
#include "../../Segmentation/Transformation/EntityTransformer.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            template<class TContainer = Foundation::SPtrEntityProxyVector>
            class TLeft {

                Foundation::SPtrColumnVector _lhsComparingColumns{};
                Foundation::SPtrColumnVector _rhsComparingColumns{};
                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                TLeft() : _sptrRhsTransformer{new Transformation::EntityTransformer{}},
                          _sptrLhsTransformer{new Transformation::EntityTransformer{}} { };

                TLeft(const TLeft &) = default;
                TLeft(TLeft &&) = default;
                TLeft &operator=(const TLeft &) = default;
                TLeft &operator=(TLeft &&) = default;
                ~TLeft() = default;

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
                TContainer Join(const TContainer &lhsVector, const TContainer &rhsVector) const {

                    using CellHelper = Foundation::Store::Helper::CellHelper;
                    using DataRecordLess = Foundation::Store::Comparer::Less;
                    using DataRecordGreater = Foundation::Store::Comparer::Greater;
                    using DataRecordCompare = Foundation::Store::Comparer::Compare<>;

                    DataRecordCompare EQ{_lhsComparingColumns, _lhsComparingColumns};
                    DataRecordLess LT{_lhsComparingColumns, _rhsComparingColumns};
                    DataRecordGreater GT{_lhsComparingColumns, _rhsComparingColumns};

                    TContainer proxiesContainer;
                    auto lhsCurrent = lhsVector.cbegin();
                    auto rhsCurrent = rhsVector.cbegin();
                    auto lhsEnd = lhsVector.cend();
                    auto rhsEnd = rhsVector.cend();

                    while (lhsCurrent != lhsEnd || rhsCurrent != rhsEnd) {

                        if (lhsCurrent == lhsEnd) {
                            break;
                        }

                        if (rhsCurrent == rhsEnd) {
                            Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++lhsCurrent;
                            continue;
                        }

                        if (lhsCurrent != lhsEnd && LT(*lhsCurrent, *rhsCurrent)) {
                            Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            proxiesContainer.insert(proxiesContainer.cend(), proxy);
                            ++lhsCurrent;
                            continue;
                        }
                        else if (rhsCurrent != rhsEnd && GT(*lhsCurrent, *rhsCurrent)) {
                            // Ignore
                            ++rhsCurrent;
                            continue;
                        }
                        else {

                            auto rhsTmp = rhsCurrent;
                            auto lhsTmp = lhsCurrent;

                            while (rhsCurrent != rhsEnd && !LT(*lhsCurrent, *rhsCurrent)) {

                                Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
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
                }
            };

            using Left = TLeft<>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_JOIN_LEFT_H
