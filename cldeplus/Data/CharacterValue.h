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

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H

#include "cldeNonSupportedFunctionException.h"
#include "Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            class CharacterValue : public Value {
                static ValueCategory _category;

            public:
                CharacterValue(ValueType dataType, size_t size);
                CharacterValue(const CharacterValue &) = default;
                CharacterValue(CharacterValue &&) = default;
                CharacterValue &operator=(const CharacterValue &) = default;
                CharacterValue &operator=(CharacterValue &&) = default;
                virtual ~CharacterValue() = default;

                const ValueCategory &getCategory() const override;
                bool isNumeric() const override;

                // IComputable
                virtual Value &operator+(const Value &rhs) override;
                virtual Value &operator-(const Value &rhs) override;
                virtual Value &operator*(const Value &rhs) override;
                virtual Value &operator/(const Value &rhs) override;
                virtual Value &operator%(const Value &rhs) override;

                // IPrimitiveAssignable
                virtual Value &operator=(bool value) override;
                virtual Value &operator=(double value) override;
                virtual Value &operator=(float value) override;
                virtual Value &operator=(int16 value) override;
                virtual Value &operator=(int32 value) override;
                virtual Value &operator=(int64 value) override;
                virtual Value &operator=(uint16 value) override;
                virtual Value &operator=(uint32 value) override;
                virtual Value &operator=(uint64 value) override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H
