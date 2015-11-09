//
// Created by LE, Duc Anh on 7/16/15.
//

#include "TimeBasedValue.h"
#include "../Exception/cldeNonSupportedFunctionException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            TimeBasedValue::TimeBasedValue(ValueType dataType, size_t size) : Value{dataType, size} {
                //
            }

            ValueCategory TimeBasedValue::_category{ValueCategory::DateTime};

            const ValueCategory &TimeBasedValue::getCategory() const {
                return _category;
            }

            bool TimeBasedValue::isNumeric() const {
                return false;
            }

            Value &TimeBasedValue::operator=(bool value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(double value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(float value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(int16 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(int32 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(int64 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(uint16 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(uint32 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }

            Value &TimeBasedValue::operator=(uint64 value) {
                throw Exception::CLDENonSupportedFunctionException("operator can not be applied to TimeBasedValue type");
            }
        }
    }
}


