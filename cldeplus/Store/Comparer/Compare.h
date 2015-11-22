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

#ifndef CLDEPLUS_FOUNDATION_STORE_COMPARER_COMPARE_H
#define CLDEPLUS_FOUNDATION_STORE_COMPARER_COMPARE_H

#include "../../EntityProxy.h"
#include "Less.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {
            namespace Comparer {

                template<class T = Comparer::Less>
                class Compare : public std::binary_function<Store::SPtrDataRecord, Store::SPtrDataRecord, bool> {

                    T _compare;

                public:
                    Compare(SPtrColumnVector const &lhsComparingColumns, SPtrColumnVector const &rhsComparingColumns)
                            : _compare{lhsComparingColumns, rhsComparingColumns} { };

                    Compare() = default;
                    Compare(Compare const &) = default;
                    Compare(Compare &&) = default;
                    Compare &operator=(Compare const &) = default;
                    Compare &operator=(Compare &&) = default;
                    ~Compare() = default;

                    // Acessors
                    SPtrColumnVector &RhsCmpColumns() { return _compare.LhsCmpColumns(); }
                    SPtrColumnVector &LhsCmpColumns() { return _compare.RhsCmpColumns(); }

                    bool operator()(Store::SPtrDataRecord const &lhs, Store::SPtrDataRecord const &rhs) const {
                        return !_compare(lhs, rhs) && !_compare(rhs, lhs);
                    };
                };
            }
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_STORE_COMPARER_COMPARE_H
