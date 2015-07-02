//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_COMPARE_H
#define CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_COMPARE_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Exception/cldeSegmentationException.h>
#include "Less.h"

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                template<class T = Comparer::Less>
                class Compare : public std::binary_function<Store::AbstractEntity, Store::AbstractEntity, bool> {

                    T _compare;

                public:
                    Compare(const SPtrColumnVector &lhsComparingColumns,
                            const SPtrColumnVector &rhsComparingColumns)
                            : _compare{lhsComparingColumns,
                                       rhsComparingColumns} { };

                    bool operator()(const Store::AbstractEntity &lhs, const Store::AbstractEntity &rhs) const {
                        return !_compare(lhs, rhs) && !_compare(rhs, lhs);
                    };
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_COMPARE_H
