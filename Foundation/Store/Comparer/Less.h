//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_LESS_H
#define CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_LESS_H

#include <Foundation/Store/AbstractEntity.h>
#include <Foundation/Data/Comparer/Less.h>
#include <Foundation/Data/Comparer/Compare.h>

namespace Cloude {
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

#endif //CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDLESS_H
