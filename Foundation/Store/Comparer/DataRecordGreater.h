//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDGREATER_H
#define CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDGREATER_H

#include <Foundation/Store/AbstractEntity.h>
#include <Foundation/Type/Comparer/cldeValueGreater.h>

namespace Cloude {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                class DataRecordGreater
                        : public std::binary_function<Store::AbstractEntity, Store::AbstractEntity, bool> {

                    const SPtrColumnVector &_lhsCmpColumns;
                    const SPtrColumnVector &_rhsCmpColumns;
                    Type::Comparer::cldeValueGreater _greater{};

                public:
                    DataRecordGreater(const SPtrColumnVector &lhsCmpColumns,
                                      const SPtrColumnVector &rhsCmpColumns)
                            : _lhsCmpColumns(lhsCmpColumns),
                              _rhsCmpColumns(rhsCmpColumns) { };

                    bool operator()(const Store::AbstractEntity &lhs, const Store::AbstractEntity &rhs) const;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_STORE_COMPARER_DATARECORDGREATER_H
