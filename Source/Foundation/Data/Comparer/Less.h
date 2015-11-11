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

#ifndef CLDEPLUS_FOUNDATION_TYPE_COMPARER_LESS_H
#define CLDEPLUS_FOUNDATION_TYPE_COMPARER_LESS_H

#include "../../Data/Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Comparer {

                class Less : public std::binary_function<SPtrValue, SPtrValue, bool> {

                public:
                    Less() = default;
                    bool operator()(const SPtrValue &lhs, const SPtrValue &rhs) const;

                protected:
                    virtual bool CompareNumeric(const SPtrValue &lhs, const SPtrValue &rhs) const;
                    virtual bool CompareCharacterBased(const SPtrValue &lhs, const SPtrValue &rhs) const;
                    virtual bool CompareDateTime(const SPtrValue &lhs, const SPtrValue &rhs) const;
                    virtual bool CompareMathematic(const SPtrValue &lhs, const SPtrValue &rhs) const;
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_TYPE_COMPARER_LESS_H
