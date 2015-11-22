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

#include "../Type/Boolean.h"
#include "../Type/Byte.h"
#include "../Type/Int16.h"
#include "../Type/Int32.h"
#include "../Type/Int64.h"
#include "../Type/UInt16.h"
#include "../Type/UInt32.h"
#include "../Type/UInt64.h"
#include "../Type/DateTime.h"
#include "../Type/Date.h"
#include "../Type/Time.h"
#include "../Type/Float.h"
#include "../Type/Double.h"
#include "../Type/String.h"
#include "../Type/VarChar.h"
#include "../Type/Text.h"
#include "../DataTypeException.h"
#include "ValueHelper.h"
#include "ValueEnumsHelper.h"

namespace CLDEPlus {
    SPtrValue Data::Helper::ValueHelper::CopySPtrValue(SPtrValue const &sptrValue) {

        switch (sptrValue->getDataType()) {
            case ValueType::Boolean: {
                auto &value = static_cast<Data::Type::Boolean &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::Boolean>(value);
                return sptrNewValue;
            }
            case ValueType::Byte: {
                // TODO: implement CopySPtrValue for Byte
                return std::dynamic_pointer_cast<Data::Type::Byte>(sptrValue);
            }
            case ValueType::Int16: {
                auto &value = static_cast<Data::Type::Int16 &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::Int16>(value);
                return sptrNewValue;
            }
            case ValueType::Int32: {
                auto &value = static_cast<Data::Type::Int32 &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::Int32>(value);
                return sptrNewValue;
            }
            case ValueType::Int64: {
                auto &value = static_cast<Data::Type::Int64 &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::Int64>(value);
                return sptrNewValue;
            }
            case ValueType::UInt16: {
                // TODO: implement CopySPtrValue for UInt16
                return std::dynamic_pointer_cast<Data::Type::UInt64>(sptrValue);
            }
            case ValueType::UInt32: {
                // TODO: implement CopySPtrValue for UInt32
                return std::dynamic_pointer_cast<Data::Type::UInt64>(sptrValue);
            }
            case ValueType::UInt64: {
                // TODO: implement CopySPtrValue for UInt64
                return std::dynamic_pointer_cast<Data::Type::UInt64>(sptrValue);
            }
            case ValueType::Double: {
                auto &value = static_cast<Data::Type::Double &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::Double>(value);
                return sptrNewValue;
            }
            case ValueType::Float: {
                auto &value = static_cast<Data::Type::Float &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::Float>(value);
                return sptrNewValue;
            }
            case ValueType::String: {
                auto &value = static_cast<Data::Type::String &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::String>(value);
                return sptrNewValue;
            }
            case ValueType::VarChar: {
                auto &value = static_cast<Data::Type::VarChar &>(*sptrValue);
                auto sptrNewValue = cldeplus_make_shared<Data::Type::VarChar>(value.CopyToString());
                return sptrNewValue;
            }
            case ValueType::Text: {
                // TODO: implement CopySPtrValue for Text
                return std::dynamic_pointer_cast<Data::Type::Text>(sptrValue);
            }
            case ValueType::Date: {
                // TODO: implement CopySPtrValue for Date
                return std::dynamic_pointer_cast<Data::Type::Date>(sptrValue);
            }
            case ValueType::Time: {
                // TODO: implement CopySPtrValue for Time
                return std::dynamic_pointer_cast<Data::Type::Time>(sptrValue);
            }
            case ValueType::DateTime: {
                // TODO: implement CopySPtrValue for DateTime
                return std::dynamic_pointer_cast<Data::Type::DateTime>(sptrValue);
            }
            default: {
                using TypeHelper = Data::Helper::ValueEnumsHelper;
                string type{ValueEnumsHelper::CopyValueTypeToString(sptrValue->getDataType())};
                string msg{"CopySPtrValue does not support " + type + " yet"};
                throw DataTypeException{msg};
            }
        }
    }
}


