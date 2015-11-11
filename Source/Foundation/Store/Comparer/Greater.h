/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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
                    Greater(SPtrColumnVector const &lhsCmpColumns, SPtrColumnVector const &rhsCmpColumns)
                            : _lhsCmpColumns(lhsCmpColumns), _rhsCmpColumns(rhsCmpColumns) { };

                    Greater() = default;
                    Greater(Greater const &) = default;
                    Greater(Greater &&) = default;
                    Greater &operator=(Greater const &) = default;
                    Greater &operator=(Greater &&) = default;
                    ~Greater() = default;

                    // Acessors
                    SPtrColumnVector &LhsCmpColumns() { return _lhsCmpColumns; }
                    SPtrColumnVector &RhsCmpColumns() { return _rhsCmpColumns; }

                    bool operator()(Store::SPtrDataRecord const &lhs, Store::SPtrDataRecord const &rhs) const;
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_STORE_COMPARER_GREATER_H
