//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYLESS_H
#define CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYLESS_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Type/Comparer/cldeValueLess.h>

namespace Cloude {
    namespace Foundation {
        namespace Comparer {

            class EntityProxyLess : std::binary_function<SPtrEntityProxy, SPtrEntityProxy, bool> {
                const SPtrColumnVector &_lhsCmpColumns;
                const SPtrColumnVector &_rhsCmpColumns;
                Type::Comparer::cldeValueLess _less{};

            public:
                EntityProxyLess(const SPtrColumnVector &lhsCmpColumns,
                                const SPtrColumnVector &rhsCmpColumns)
                        : _lhsCmpColumns(lhsCmpColumns),
                          _rhsCmpColumns(rhsCmpColumns) { };

                bool operator()(const SPtrEntityProxy &lhs, const SPtrEntityProxy &rhs) const;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYLESS_H
