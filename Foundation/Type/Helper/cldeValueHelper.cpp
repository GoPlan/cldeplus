//
// Created by LE, Duc Anh on 6/24/15.
//

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
#include "cldeValueHelper.h"

namespace Cloude {
    namespace Foundation {

        Type::SPtrCldeValue Type::Helper::cldeValueHelper::CopySPtrValue(const Type::SPtrCldeValue &sptrValue) {

            switch (sptrValue->getDataType()) {
                case cldeValueType::Boolean: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeBoolean>(sptrValue);;
                }
                case cldeValueType::Byte: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeByte>(sptrValue);
                }
                case cldeValueType::Int16: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeInt16>(sptrValue);
                }
                case cldeValueType::Int32: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeInt32>(sptrValue);
                }
                case cldeValueType::Int64: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeInt64>(sptrValue);
                }
                case cldeValueType::UInt16: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt16>(sptrValue);
                }
                case cldeValueType::UInt32: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt32>(sptrValue);
                }
                case cldeValueType::UInt64: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::Double: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::Float: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::Decimal: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::String: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::Varchar: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::Text: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeUInt64>(sptrValue);
                }
                case cldeValueType::Currency: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeCurrency>(sptrValue);
                }
                case cldeValueType::Date: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeDate>(sptrValue);
                }
                case cldeValueType::Time: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeTime>(sptrValue);
                }
                case cldeValueType::DateTime: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeDateTime>(sptrValue);
                }
                case cldeValueType::Timestamp: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeTimeStamp>(sptrValue);
                }
                case cldeValueType::Point: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldePoint>(sptrValue);
                }
                case cldeValueType::Matrix: {
                    return std::dynamic_pointer_cast<Type::Implementation::cldeMatrix>(sptrValue);
                }
            }
        }
    }
}


