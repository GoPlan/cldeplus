//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDLESS_H
#define CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDLESS_H

#include <Foundation/Store/AbstractionEntity.h>
#include <Foundation/Type/Comparer/cldeValueLess.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                class DataRecordLess :
                        public std::binary_function<Store::AbstractionEntity, Store::AbstractionEntity, bool> {

                    const SPtrColumnVector &_lhsCmpColumns;
                    const SPtrColumnVector &_rhsCmpColumns;
                    Type::Comparer::cldeValueLess _less{};

                public:
                    DataRecordLess(const SPtrColumnVector &lhsCmpColumns,
                                   const SPtrColumnVector &rhsCmpColumns)
                            : _lhsCmpColumns(lhsCmpColumns),
                              _rhsCmpColumns(rhsCmpColumns) { };

                    bool operator()(const Store::AbstractionEntity &lhs, const Store::AbstractionEntity &rhs) const;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDLESS_H
