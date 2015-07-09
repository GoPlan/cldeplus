//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_GREATER_H
#define CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_GREATER_H

#include <Foundation/Store/AbstractEntity.h>
#include <Foundation/Data/Comparer/Greater.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                class Greater : public std::binary_function<Store::SPtrDataRecord, Store::SPtrDataRecord, bool> {

                    SPtrColumnVector _lhsCmpColumns;
                    SPtrColumnVector _rhsCmpColumns;
                    Data::Comparer::Greater _greater{};

                public:
                    Greater(const SPtrColumnVector &lhsCmpColumns, const SPtrColumnVector &rhsCmpColumns)
                            : _lhsCmpColumns(lhsCmpColumns), _rhsCmpColumns(rhsCmpColumns) { };

                    Greater() = default;
                    Greater(const Greater &) = default;
                    Greater(Greater &&) = default;
                    Greater &operator=(const Greater &) = default;
                    Greater &operator=(Greater &&) = default;
                    ~Greater() = default;

                    // Acessors
                    SPtrColumnVector &LhsCmpColumns() { return _lhsCmpColumns; }
                    SPtrColumnVector &RhsCmpColumns() { return _rhsCmpColumns; }

                    bool operator()(const Store::SPtrDataRecord &lhs, const Store::SPtrDataRecord &rhs) const;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_GREATER_H
