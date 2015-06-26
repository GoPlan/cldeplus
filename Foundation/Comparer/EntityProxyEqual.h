//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCOMPARER_H
#define CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCOMPARER_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Exception/cldeSegmentationException.h>
#include <Foundation/Comparer/EntityProxyLess.h>

namespace Cloude {
    namespace Foundation {
        namespace Comparer {

            template<class T = Comparer::EntityProxyLess>
            class EntityProxyEqual : std::binary_function<SPtrEntityProxy, SPtrEntityProxy, bool> {
                T _compare;

            public:
                EntityProxyEqual(const SPtrColumnVector &lhsComparingColumns,
                                 const SPtrColumnVector &rhsComparingColumns)
                        : _compare{lhsComparingColumns,
                                   rhsComparingColumns} { };

                bool operator()(const SPtrEntityProxy &lhs, const SPtrEntityProxy &rhs) const {
                    return !_compare(lhs, rhs) && !_compare(rhs, lhs);
                };
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCOMPARER_H
