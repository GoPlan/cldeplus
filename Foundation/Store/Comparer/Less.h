//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_LESS_H
#define CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_LESS_H

#include <Foundation/Data/Comparer/Less.h>
#include <Foundation/Store/AbstractEntity.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                class Less : public std::binary_function<Store::AbstractEntity, Store::AbstractEntity, bool> {

                    const SPtrColumnVector &_lhsCmpColumns;
                    const SPtrColumnVector &_rhsCmpColumns;
                    Data::Comparer::Less _less{};

                public:
                    Less(const SPtrColumnVector &lhsCmpColumns,
                         const SPtrColumnVector &rhsCmpColumns)
                            : _lhsCmpColumns(lhsCmpColumns),
                              _rhsCmpColumns(rhsCmpColumns) { };

                    bool operator()(const Store::AbstractEntity &lhs, const Store::AbstractEntity &rhs) const;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDLESS_H
