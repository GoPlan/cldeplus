//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLDEPLUS_FOUNDATION_STORE_COMPARER_GREATER_H
#define CLDEPLUS_FOUNDATION_STORE_COMPARER_GREATER_H

#include "../AbstractEntity.h"
#include "../../Data/Comparer/Greater.h"
#include "../../Data/Comparer/Compare.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                class Greater : public std::binary_function<Store::SPtrDataRecord, Store::SPtrDataRecord, bool> {

                    SPtrColumnVector _lhsCmpColumns;
                    SPtrColumnVector _rhsCmpColumns;
                    Data::Comparer::Greater _greater{};
                    Data::Comparer::Compare _equal{};

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


#endif //CLDEPLUS_FOUNDATION_STORE_COMPARER_GREATER_H
