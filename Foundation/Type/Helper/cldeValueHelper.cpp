//
// Created by LE, Duc Anh on 6/24/15.
//

#include <memory>
#include <Foundation/Type/Implementation/cldeBoolean.h>
#include <Foundation/Type/Implementation/cldeByte.h>
#include <Foundation/Type/Implementation/cldeInt16.h>
#include <Foundation/Type/Implementation/cldeInt32.h>
#include <Foundation/Type/Implementation/cldeInt64.h>
#include <Foundation/Type/Implementation/cldeUInt16.h>
#include <Foundation/Type/Implementation/cldeUInt32.h>
#include <Foundation/Type/Implementation/cldeUInt64.h>
#include <Foundation/Type/Implementation/cldeMatrix.h>
#include <Foundation/Type/Implementation/cldePoint.h>
#include <Foundation/Type/Implementation/cldeTimeStamp.h>
#include <Foundation/Type/Implementation/cldeTime.h>
#include <Foundation/Type/Implementation/cldeDate.h>
#include <Foundation/Type/Implementation/cldeCurrency.h>
#include <Foundation/Type/Implementation/cldeDateTime.h>
#include <Foundation/Type/Implementation/cldeDouble.h>
#include <Foundation/Type/Implementation/cldeFloat.h>
#include <Foundation/Type/Implementation/cldeString.h>
#include <Foundation/Type/Implementation/cldeVarChar.h>
#include <Foundation/Type/Implementation/cldeText.h>
#include "cldeValueHelper.h"

namespace Cloude {
    namespace Foundation {

        Type::SPtrCldeValue Type::Helper::cldeValueHelper::CopySPtrValue(const Type::SPtrCldeValue &sptrValue) {

            switch (sptrValue->getDataType()) {
                case cldeValueType::Boolean: {
                    auto &value = static_cast<Type::Implementation::cldeBoolean &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeBoolean>(value);
                    return sptrNewValue;
                }
                case cldeValueType::Byte: {
                    // TODO: implement CopySPtrValue for cldeByte
                    return std::dynamic_pointer_cast<Type::Implementation::cldeByte>(sptrValue);
                }
                case cldeValueType::Int16: {
                    auto &value = static_cast<Type::Implementation::cldeInt16 &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeInt16>(value);
                    return sptrNewValue;
                }
                case cldeValueType::Int32: {
                    auto &value = static_cast<Type::Implementation::cldeInt32 &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeInt32>(value);
                    return sptrNewValue;
                }
                case cldeValueType::Int64: {
                    auto &value = static_cast<Type::Implementation::cldeInt64 &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeInt64>(value);
                    return sptrNewValue;
                }
                case cldeValueType::UInt16: {
                    // TODO: implement CopySPtrValue for UInt16
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::UInt32: {
                    // TODO: implement CopySPtrValue for UInt32
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::UInt64: {
                    // TODO: implement CopySPtrValue for UInt64
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::Double: {
                    auto &value = static_cast<Type::Implementation::cldeDouble &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeDouble>(value);
                    return sptrNewValue;
                }
                case cldeValueType::Float: {
                    auto &value = static_cast<Type::Implementation::cldeFloat &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeFloat>(value);
                    return sptrNewValue;
                }
                case cldeValueType::String: {
                    auto &value = static_cast<Type::Implementation::cldeString &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeString>(value);
                    return sptrNewValue;
                }
                case cldeValueType::VarChar: {
                    auto &value = static_cast<Type::Implementation::cldeVarChar &>(*sptrValue);
                    auto sptrNewValue = std::make_shared<Type::Implementation::cldeVarChar>(value.ToCString());
                    return sptrNewValue;
                }
                case cldeValueType::Text: {
                    // TODO: implement CopySPtrValue for Text
                    return std::dynamic_pointer_cast<Type::Implementation::cldeText>(sptrValue);
                }
                case cldeValueType::Currency: {
                    // TODO: implement CopySPtrValue for Currency
                    return std::dynamic_pointer_cast<Type::Implementation::cldeCurrency>(sptrValue);
                }
                case cldeValueType::Date: {
                    // TODO: implement CopySPtrValue for Date
                    return std::dynamic_pointer_cast<Type::Implementation::cldeDate>(sptrValue);
                }
                case cldeValueType::Time: {
                    // TODO: implement CopySPtrValue for Time
                    return std::dynamic_pointer_cast<Type::Implementation::cldeTime>(sptrValue);
                }
                case cldeValueType::DateTime: {
                    // TODO: implement CopySPtrValue for DateTime
                    return std::dynamic_pointer_cast<Type::Implementation::cldeDateTime>(sptrValue);
                }
                case cldeValueType::TimeStamp: {
                    // TODO: implement CopySPtrValue for TimeStamp
                    return std::dynamic_pointer_cast<Type::Implementation::cldeTimeStamp>(sptrValue);
                }
                case cldeValueType::Point: {
                    // TODO: implement CopySPtrValue for Point
                    return std::dynamic_pointer_cast<Type::Implementation::cldePoint>(sptrValue);
                }
                case cldeValueType::Matrix: {
                    // TODO: implement CopySPtrValue for Matrix
                    return std::dynamic_pointer_cast<Type::Implementation::cldeMatrix>(sptrValue);
                }
            }
        }
    }
}


