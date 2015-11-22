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

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H

#include "../../Portable/CommonTypes.h"
#include "../Common/IPrintable.h"
#include "../Common/IComputable.h"
#include "../Common/IPrimitiveAssignable.h"
#include "ValueEnums.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            class Value : public Common::IPrintable {

            public:
                Value(ValueType dataType, size_t size);

                virtual size_t getActualSize() { return _actualSize; }
                virtual const ValueCategory &getCategory() const = 0;
                virtual bool isNumeric() const = 0;
                virtual void *PointerToBuffer() = 0;
                virtual void *PointerToActualSizeVar() { return &_actualSize; };

                //
                void *PointerToReservedSizeVar() { return &_reservedSize; }
                size_t getReservedSize() const { return _reservedSize; }
                ValueType getDataType() const { return _dataType; }

                //
                virtual Value &operator+(Value const &rhs) = 0;
                virtual Value &operator-(Value const &rhs) = 0;
                virtual Value &operator*(Value const &rhs) = 0;
                virtual Value &operator/(Value const &rhs) = 0;
                virtual Value &operator%(Value const &rhs) = 0;

                //
                virtual Value &operator=(bool value) = 0;
                virtual Value &operator=(double value) = 0;
                virtual Value &operator=(float value) = 0;
                virtual Value &operator=(int16 value) = 0;
                virtual Value &operator=(int32 value) = 0;
                virtual Value &operator=(int64 value) = 0;
                virtual Value &operator=(uint16 value) = 0;
                virtual Value &operator=(uint32 value) = 0;
                virtual Value &operator=(uint64 value) = 0;

            protected:
                ValueType _dataType;
                size_t _reservedSize;
                size_t _actualSize;

            };

            using SPtrValue = shared_ptr<Value>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUE_H
