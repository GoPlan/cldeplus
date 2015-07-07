//
// Created by LE, Duc Anh on 6/23/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_JOIN_INNER_H
#define CLOUD_E_PLUS_SEGMENTATION_JOIN_INNER_H

#include <Foundation/Store/Comparer/Compare.h>
#include <Foundation/Store/Comparer/Greater.h>
#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/EntityProxy.h>
#include <Segmentation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            template<class TContainer = Foundation::SPtrEntityProxyVector>
            class TInner {

                Foundation::SPtrColumnVector _lhsComparingColumns{};
                Foundation::SPtrColumnVector _rhsComparingColumns{};
                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                TInner() : _sptrRhsTransformer{new Transformation::EntityTransformer{}},
                           _sptrLhsTransformer{new Transformation::EntityTransformer{}} { };

                TInner(const TInner &) = default;
                TInner(TInner &&) = default;
                TInner &operator=(const TInner &) = default;
                TInner &operator=(TInner &&) = default;
                ~TInner() = default;

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

                    DataRecordCompare compare{_lhsComparingColumns, _lhsComparingColumns};
                    DataRecordLess lesser{_lhsComparingColumns, _rhsComparingColumns};
                    DataRecordGreater greater{_lhsComparingColumns, _rhsComparingColumns};

                    TContainer proxiesContainer;
                    auto lhsCurrent = lhsContainer.cbegin();
                    auto rhsCurrent = rhsContainer.cbegin();
                    auto lhsEnd = lhsContainer.cend();
                    auto rhsEnd = rhsContainer.cend();

                    while (lhsCurrent != lhsEnd && rhsCurrent != rhsEnd) {

                        if (lhsCurrent != lhsEnd && lesser(*lhsCurrent, *rhsCurrent)) {
                            // Ignore
                            ++lhsCurrent;
                            continue;
                        }
                        else if (rhsCurrent != rhsEnd && greater(*lhsCurrent, *rhsCurrent)) {
                            // Ignore
                            ++rhsCurrent;
                            continue;
                        }
                        else {

                            auto rhsTmp = rhsCurrent;
                            auto lhsTmp = lhsCurrent;

                            while (rhsCurrent != rhsEnd && !lesser(*lhsCurrent, *rhsCurrent)) {

                                Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                                _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                                _sptrRhsTransformer->Transform(*rhsCurrent, proxy);

                                proxiesContainer.insert(proxiesContainer.cend(), proxy);
                                ++rhsCurrent;
                            }

                            ++lhsCurrent;

                            if (lhsCurrent != lhsEnd && compare(*lhsTmp, *(lhsCurrent)))
                                rhsCurrent = rhsTmp;
                        }
                    }

                    return proxiesContainer;
                }
            };

            using Inner = TInner<>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_JOIN_INNER_H
