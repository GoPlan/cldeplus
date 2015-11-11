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

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_NUMERICVALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_NUMERICVALUE_H

#include "../Common/IComputable.h"
#include "Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            class NumericValue : public Value {

                static ValueCategory _category;

            public:
                NumericValue(ValueType dataType, size_t size);
                NumericValue(NumericValue const &) = default;
                NumericValue(NumericValue &&) = default;
                NumericValue &operator=(NumericValue const &) = default;
                NumericValue &operator=(NumericValue &&) = default;
                virtual ~NumericValue() = default;

                const ValueCategory &getCategory() const override;
                bool isNumeric() const override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_NUMERICVALUE_H
