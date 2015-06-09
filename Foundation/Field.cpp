//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"
#include "Exception/NonSupportedDataTypeException.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

        Field::Field(const shared_ptr<Column> &column) : _column(column) {
            ResetField();
        }

        void Field::ResetField() {
            _voidPtr = nullptr;
            _string.empty();
            _bool = false;
            _double = 0;
            _float = 0;
            _int8 = 0;
            _int16 = 0;
            _int32 = 0;
            _int64 = 0;
            _uint8 = 0;
            _uint16 = 0;
            _uint32 = 0;
            _uint64 = 0;
        }

        void *Field::PointerToFieldValue() {
            switch (_column->getDbType()) {
                case Enumeration::DbType::Boolean:
                    return &_bool;
                case Enumeration::DbType::Byte:
                    return &_char;
                case Enumeration::DbType::Int16:
                    return &_int16;
                case Enumeration::DbType::Int32:
                    return &_int32;
                case Enumeration::DbType::Int64:
                    return &_int64;
                case Enumeration::DbType::UInt16:
                    return &_uint16;
                case Enumeration::DbType::UInt32:
                    return &_uint32;
                case Enumeration::DbType::UInt64:
                    return &_uint64;
                case Enumeration::DbType::Double:
                    return &_double;
                case Enumeration::DbType::Float:
                    return &_float;
                case Enumeration::DbType::Decimal:
                    throw Exception::NonSupportedDataTypeException();
                case Enumeration::DbType::Numeric:
                    throw Exception::NonSupportedDataTypeException();
                case Enumeration::DbType::String:
                    return &_cstr;
                case Enumeration::DbType::Currency:
                    throw Exception::NonSupportedDataTypeException();
                case Enumeration::DbType::Date:
                    throw Exception::NonSupportedDataTypeException();
                case Enumeration::DbType::Time:
                    throw Exception::NonSupportedDataTypeException();
                case Enumeration::DbType::Timestamp:
                    throw Exception::NonSupportedDataTypeException();
                case Enumeration::DbType::Interval:
                    throw Exception::NonSupportedDataTypeException();
            }
        }
    }
}