//
// Created by LE, Duc Anh on 6/24/15.
//

#include <memory>
#include <Foundation/Data/Type/Boolean.h>
#include <Foundation/Data/Type/Byte.h>
#include <Foundation/Data/Type/Int16.h>
#include <Foundation/Data/Type/Int32.h>
#include <Foundation/Data/Type/Int64.h>
#include <Foundation/Data/Type/UInt16.h>
#include <Foundation/Data/Type/UInt32.h>
#include <Foundation/Data/Type/UInt64.h>
#include <Foundation/Data/Type/Matrix.h>
#include <Foundation/Data/Type/Point.h>
#include <Foundation/Data/Type/TimeStamp.h>
#include <Foundation/Data/Type/Time.h>
#include <Foundation/Data/Type/Date.h>
#include <Foundation/Data/Type/Currency.h>
#include <Foundation/Data/Type/DateTime.h>
#include <Foundation/Data/Type/Float.h>
#include <Foundation/Data/Type/Double.h>
#include <Foundation/Data/Type/String.h>
#include <Foundation/Data/Type/VarChar.h>
#include <Foundation/Data/Type/Text.h>
#include "ValueHelper.h"

namespace Cloude {
    namespace Foundation {

        Data::SPtrValue Data::Helper::ValueHelper::CopySPtrValue(const Data::SPtrValue &sptrValue) {

            switch (sptrValue->getDataType()) {
                case ValueType ::Boolean: {
                    auto &value = static_cast<Data::Type::Boolean &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Data::Type::Boolean>(value);
                    return sptrNewValue;
                }
                case ValueType::Byte: {
                    // TODO: implement CopySPtrValue for Byte
                    return std::dynamic_pointer_cast<Data::Type::Byte>(sptrValue);
                }
                case ValueType::Int16: {
                    auto &value = static_cast<Data::Type::Int16 &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Data::Type::Int16>(value);
                    return sptrNewValue;
                }
                case ValueType::Int32: {
                    auto &value = static_cast<Data::Type::Int32 &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Data::Type::Int32>(value);
                    return sptrNewValue;
                }
                case ValueType::Int64: {
                    auto &value = static_cast<Data::Type::Int64 &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Data::Type::Int64>(value);
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
                    auto sptrNewValue = std::make_shared<Data::Type::Double>(value);
                    return sptrNewValue;
                }
                case ValueType::Float: {
                    auto &value = static_cast<Data::Type::Float &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Data::Type::Float>(value);
                    return sptrNewValue;
                }
                case ValueType::String: {
                    auto &value = static_cast<Data::Type::String &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Data::Type::String>(value);
                    return sptrNewValue;
                }
                case ValueType::VarChar: {
                    auto &value = static_cast<Data::Type::VarChar &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Data::Type::VarChar>(value.ToCString());
                    return sptrNewValue;
                }
                case ValueType::Text: {
                    // TODO: implement CopySPtrValue for Text
                    return std::dynamic_pointer_cast<Data::Type::Text>(sptrValue);
                }
                case ValueType::Currency: {
                    // TODO: implement CopySPtrValue for Currency
                    return std::dynamic_pointer_cast<Data::Type::Currency>(sptrValue);
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
                case ValueType::TimeStamp: {
                    // TODO: implement CopySPtrValue for TimeStamp
                    return std::dynamic_pointer_cast<Data::Type::TimeStamp>(sptrValue);
                }
                case ValueType::Point: {
                    // TODO: implement CopySPtrValue for Point
                    return std::dynamic_pointer_cast<Data::Type::Point>(sptrValue);
                }
                case ValueType::Matrix: {
                    // TODO: implement CopySPtrValue for Matrix
                    return std::dynamic_pointer_cast<Data::Type::Matrix>(sptrValue);
                }
            }
        }
    }
}


