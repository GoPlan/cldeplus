//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/Store/Comparer/DataRecordCompare.h>
#include "Cross.h"

namespace Cloude {
    namespace Foundation {

        SPtrEntityProxySet Segmentation::Helper::Cross::operator()(const SPtrEntityProxySet &lhsSet,
                                                                   const SPtrEntityProxySet &rhsSet) const {

            using CellHelper = Store::Helper::CellHelper;
            using DataRecordLess = Store::Comparer::DataRecordLess;
            using DataRecordCompare = Store::Comparer::DataRecordCompare<>;

            DataRecordCompare compare{_lhsComparingColumns, _rhsComparingColumns};
            DataRecordLess lesser{_lhsComparingColumns, _rhsComparingColumns};

            SPtrEntityProxySet setProxies;
            auto lhsCurrent = lhsSet.cbegin();
            auto rhsCurrent = rhsSet.cbegin();
            auto lhsEnd = lhsSet.cend();
            auto rhsEnd = rhsSet.cend();

            while (lhsCurrent != lhsEnd || rhsCurrent != rhsEnd) {

                if (rhsCurrent == rhsEnd) {
                    SPtrEntityProxy proxy = _sptrTransformer->TransformLeftOnly(*lhsCurrent++);
                    setProxies.insert(proxy);
                    continue;
                }

                if (lhsCurrent == lhsEnd) {
                    SPtrEntityProxy proxy = _sptrTransformer->TransformRightOnly(*rhsCurrent++);
                    setProxies.insert(proxy);
                    continue;
                }

                if (lhsCurrent != lhsEnd && lesser(**lhsCurrent, **rhsCurrent)) {
                    SPtrEntityProxy proxy = _sptrTransformer->TransformLeftOnly(*lhsCurrent++);
                    setProxies.insert(proxy);
                    continue;
                }
                else if (rhsCurrent != rhsEnd && lesser(**rhsCurrent, **lhsCurrent)) {
                    SPtrEntityProxy proxy = _sptrTransformer->TransformRightOnly(*rhsCurrent++);
                    setProxies.insert(proxy);
                    continue;
                }
                else {

                    auto rhsTmp = rhsCurrent;

                    while (!lesser(**lhsCurrent, **rhsCurrent)) {
                        SPtrEntityProxy proxy = _sptrTransformer->Transform(*lhsCurrent, *rhsCurrent);
                        setProxies.insert(proxy);
                        ++rhsCurrent;
                    }

                    if (compare(**lhsCurrent, **(++lhsCurrent))) rhsCurrent = rhsTmp;
                }
            }

            return setProxies;
        }
    }
}


