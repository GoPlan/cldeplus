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

#include "NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            NumericValue::NumericValue(ValueType dataType, size_t size)
                    : Value(dataType, size) {
                //
            }

            ValueCategory NumericValue::_category = ValueCategory::Numeric;

            const ValueCategory &NumericValue::getCategory() const { return _category; }

            bool NumericValue::isNumeric() const { return true; }

        }
    }
}


