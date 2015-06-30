//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/Store/Comparer/DataRecordCompare.h>
#include "Cross.h"

namespace Cloude {
    namespace Foundation {

        Segmentation::Helper::Cross::Cross(const Segmentation::JoinPhrase &lhsJoinPhrase,
                                           const Segmentation::JoinPhrase &rhsJoinPhrase)
                : _lhs{lhsJoinPhrase}, _rhs{rhsJoinPhrase}, _transformer{lhsJoinPhrase, rhsJoinPhrase} {
            //
        }

        SPtrEntityProxySet Segmentation::Helper::Cross::operator()(const SPtrEntityProxySet &lhsSet,
                                                                   const SPtrEntityProxySet &rhsSet) const {

            using CellHelper = Store::Helper::CellHelper;
            using DataRecordLess = Store::Comparer::DataRecordLess;
            using DataRecordCompare = Store::Comparer::DataRecordCompare<>;

            DataRecordCompare compare{_lhs.CComparingColumns(), _rhs.CComparingColumns()};
            DataRecordLess lesser{_lhs.CComparingColumns(), _rhs.CComparingColumns()};

            SPtrEntityProxySet setProxies;
            auto lhsCurrent = lhsSet.cbegin();
            auto rhsCurrent = rhsSet.cbegin();
            auto lhsEnd = lhsSet.cend();
            auto rhsEnd = rhsSet.cend();

            while (lhsCurrent != lhsEnd || rhsCurrent != rhsEnd) {

                if (rhsCurrent == rhsEnd) {

                }

                if (lhsCurrent == lhsEnd) {

                }

                if (lhsCurrent != lhsEnd && lesser(**lhsCurrent, **rhsCurrent)) {


                }
                else if (rhsCurrent != rhsEnd && lesser(**rhsCurrent, **lhsCurrent)) {


                }
                else {

                    auto rhsTmp = rhsCurrent;

                    while (!lesser(**lhsCurrent, **rhsCurrent)) {


                    }

                    if (compare(**lhsCurrent, **(++lhsCurrent))) rhsCurrent = rhsTmp;
                }
            }

            return setProxies;
        }
    }
}


