//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLDEPLUS_FOUNDATION_STORE_COMPARER_LESS_H
#define CLDEPLUS_FOUNDATION_STORE_COMPARER_LESS_H

#include "../AbstractEntity.h"
#include "../../Data/Comparer/Less.h"
#include "../../Data/Comparer/Compare.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                class Less : public std::binary_function<Store::SPtrDataRecord, Store::SPtrDataRecord, bool> {

                    SPtrColumnVector _lhsCmpColumns{};
                    SPtrColumnVector _rhsCmpColumns{};
                    Data::Comparer::Less _less{};
                    Data::Comparer::Compare _equal{};

                public:
                    Less(const SPtrColumnVector &lhsCmpColumns, const SPtrColumnVector &rhsCmpColumns)
                            : _lhsCmpColumns(lhsCmpColumns), _rhsCmpColumns(rhsCmpColumns) { };

                    Less() = default;
                    Less(const Less &) = default;
                    Less(Less &&) = default;
                    Less &operator=(const Less &) = default;
                    Less &operator=(Less &&) = default;
                    ~Less() = default;

                    SPtrColumnVector &LhsCmpColumns() { return _lhsCmpColumns; }
                    SPtrColumnVector &RhsCmpColumns() { return _rhsCmpColumns; }

                    bool operator()(const Store::SPtrDataRecord &lhs, const Store::SPtrDataRecord &rhs) const;
                };
            }
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_STORE_COMPARER_DATARECORDLESS_H
