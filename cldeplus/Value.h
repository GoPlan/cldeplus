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

#ifndef CLDECPLUS_VALUE_H
#define CLDECPLUS_VALUE_H

#include "CldePlus-Portable.h"
#include "CldePlus-Commons.h"

namespace CLDEPlus {

    enum class ValueCategory {
        Numeric,
        DateTime,
        CharacterBased,
        Mathematic,
        UserDefined
    };

    enum class ValueType {
        Boolean,
        Byte,
        Int16,
        Int32,
        Int64,
        UInt16,
        UInt32,
        UInt64,
        Double,
        Float,
        String,
        VarChar,
        Text,
        DateTime,
        Date,
        Time,
    };

    class Value : public IPrintable {

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
    using UptrValue = unique_ptr<Value>;
}


#endif //CLDECPLUS_VALUE_H
