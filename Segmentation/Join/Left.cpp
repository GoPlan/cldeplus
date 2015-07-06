//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/Store/Comparer/Less.h>
#include <Foundation/Store/Comparer/Compare.h>
#include <Foundation/Store/Comparer/Greater.h>
#include "Left.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            Left::Left() {
                _sptrLhsTransformer = std::make_shared<Segmentation::Transformation::EntityTransformer>();
                _sptrRhsTransformer = std::make_shared<Segmentation::Transformation::EntityTransformer>();
            }

            Foundation::SPtrEntityProxySet Left::operator()(
                    const Foundation::SPtrEntityProxySet &lhsSet,
                    const Foundation::SPtrEntityProxySet &rhsSet) const {

                using CellHelper = Foundation::Store::Helper::CellHelper;
                using DataRecordLess = Foundation::Store::Comparer::Less;
                using DataRecordGreater = Foundation::Store::Comparer::Greater;
                using DataRecordCompare = Foundation::Store::Comparer::Compare<>;

                DataRecordCompare compare{_lhsComparingColumns, _lhsComparingColumns};
                DataRecordLess lesser{_lhsComparingColumns, _rhsComparingColumns};
                DataRecordGreater greater{_lhsComparingColumns, _rhsComparingColumns};

                Foundation::SPtrEntityProxySet setProxies;
                auto lhsCurrent = lhsSet.cbegin();
                auto rhsCurrent = rhsSet.cbegin();
                auto lhsEnd = lhsSet.cend();
                auto rhsEnd = rhsSet.cend();

                while (lhsCurrent != lhsEnd || rhsCurrent != rhsEnd) {

                    if (rhsCurrent == rhsEnd) {
                        Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                        _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                        setProxies.insert(proxy);
                        ++lhsCurrent;
                        continue;
                    }

                    if (lhsCurrent != lhsEnd && lesser(**lhsCurrent, **rhsCurrent)) {
                        Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                        _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                        setProxies.insert(proxy);
                        ++lhsCurrent;
                        continue;
                    }
                    else if (rhsCurrent != rhsEnd && greater(**lhsCurrent, **rhsCurrent)) {
                        // Ignore
                        ++rhsCurrent;
                        continue;
                    }
                    else {

                        auto rhsTmp = rhsCurrent;
                        auto lhsTmp = lhsCurrent;

                        while (!lesser(**lhsCurrent, **rhsCurrent)) {

                            Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            _sptrRhsTransformer->Transform(*rhsCurrent, proxy);

                            setProxies.insert(proxy);
                            ++rhsCurrent;
                        }

                        ++lhsCurrent;
                        if (compare(**lhsTmp, **(lhsCurrent))) rhsCurrent = rhsTmp;
                    }
                }

                return setProxies;
            }
        }
    }
}

