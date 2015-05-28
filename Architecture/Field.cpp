//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"
#include "Exception/NonSupportedDataTypeException.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        Field::Field(const shared_ptr<Column> &column) : _column(column) {
            ResetField();
        }

        Field::Field(const std::shared_ptr<Column> &column, long value) : _column(column),
                                                                          _int64(value) {
            //
        }

        Field::Field(const std::shared_ptr<Column> &column, unsigned long value) : _column(column),
                                                                                   _uint64(value) {
            //
        }

        Field::Field(const std::shared_ptr<Column> &column, double value) : _column(column),
                                                                            _double(value) {
            //
        }

        Field::Field(const shared_ptr<Column> &column, const std::string &value) : _column(column),
                                                                                   _string(value) {
            //
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
                case Enumeration::DbType::String:
                    return &_cstr;
                case Enumeration::DbType::Currency:
                    throw Exception::NonSupportedDataTypeException();
            }
        }
    }
}