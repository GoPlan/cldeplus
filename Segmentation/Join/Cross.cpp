//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/Store/Comparer/Compare.h>
#include <Foundation/Store/Comparer/Less.h>
#include "Cross.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            Foundation::SPtrEntityProxySet Cross::operator()(
                    const Foundation::SPtrEntityProxySet &lhsSet,
                    const Foundation::SPtrEntityProxySet &rhsSet) const {

                using CellHelper = Foundation::Store::Helper::CellHelper;
                using DataRecordLess = Foundation::Store::Comparer::Less;
                using DataRecordCompare = Foundation::Store::Comparer::Compare<>;

                DataRecordCompare compare{_lhsComparingColumns, _rhsComparingColumns};
                DataRecordLess lesser{_lhsComparingColumns, _rhsComparingColumns};

                Foundation::SPtrEntityProxySet setProxies;
                auto lhsCurrent = lhsSet.cbegin();
                auto rhsCurrent = rhsSet.cbegin();
                auto lhsEnd = lhsSet.cend();
                auto rhsEnd = rhsSet.cend();

                while (lhsCurrent != lhsEnd || rhsCurrent != rhsEnd) {

                    if (rhsCurrent == rhsEnd) {
                        Foundation::SPtrEntityProxy proxy{};
                        _sptrLhsTransformer->Transform(*lhsCurrent++, proxy);
                        setProxies.insert(proxy);
                        continue;
                    }

                    if (lhsCurrent == lhsEnd) {
                        Foundation::SPtrEntityProxy proxy{};
                        _sptrRhsTransformer->Transform(*rhsCurrent++, proxy);
                        setProxies.insert(proxy);
                        continue;
                    }

                    if (lhsCurrent != lhsEnd && lesser(**lhsCurrent, **rhsCurrent)) {
                        Foundation::SPtrEntityProxy proxy{};
                        _sptrLhsTransformer->Transform(*lhsCurrent++, proxy);
                        setProxies.insert(proxy);
                        continue;
                    }
                    else if (rhsCurrent != rhsEnd && lesser(**rhsCurrent, **lhsCurrent)) {
                        Foundation::SPtrEntityProxy proxy{};
                        _sptrRhsTransformer->Transform(*rhsCurrent++, proxy);
                        setProxies.insert(proxy);
                        continue;
                    }
                    else {

                        auto rhsTmp = rhsCurrent;

                        while (!lesser(**lhsCurrent, **rhsCurrent)) {

                            Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            _sptrLhsTransformer->Transform(*rhsCurrent, proxy);

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
}


