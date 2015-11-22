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

#ifndef CLDEPLUS_DATA_TYPE_INT32_H
#define CLDEPLUS_DATA_TYPE_INT32_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Data {
        namespace Type {

            class Int32 : public Data::NumericValue {

                int32_t _value = 0;

            public:
                explicit Int32(int32_t value);
                Int32(Int32 const &) = default;
                Int32(Int32 &&) = default;
                Int32 &operator=(Int32 const &) = default;
                Int32 &operator=(Int32 &&) = default;
                ~Int32() = default;

                // Value
                virtual void *PointerToBuffer() override;

                // IPrintable
                virtual string ToString() const override;

                // IComputable
                virtual Value &operator+(Value const &rhs) override;
                virtual Value &operator-(Value const &rhs) override;
                virtual Value &operator*(Value const &rhs) override;
                virtual Value &operator/(Value const &rhs) override;
                virtual Value &operator%(Value const &rhs) override;

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

#endif //CLDEPLUS_DATA_TYPE_INT32_H
