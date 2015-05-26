//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"
#include "Exception/NonSupportedDataTypeException.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        Field::Field(shared_ptr<Column> column) : _column(column) {
            ResetField();
        }

        Field::Field(std::shared_ptr<Column> column, long value) : _column(column),
                                                                   _int64(value) {
            //
        }

        Field::Field(std::shared_ptr<Column> column, unsigned long value) : _column(column),
                                                                            _uint64(value) {
            //
        }

        Field::Field(std::shared_ptr<Column> column, double value) : _column(column),
                                                                     _double(value) {
            //
        }

        Field::Field(shared_ptr<Column> column, const std::string &value) : _column(column),
                                                                            _string(value) {
            //
        }

        void Field::ResetField() {
            _voidPtr = 0;
            _bool = 0;
            _string.empty();
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

        void Field::AssignDataPointer(void *ptr) {

            switch (_column->getDbType()) {
                case Enumeration::DbType::Boolean:
                    ptr = &_bool;
                    break;
                case Enumeration::DbType::Byte:
                    ptr = &_char;
                    break;
                case Enumeration::DbType::Int16:
                    ptr = &_int16;
                    break;
                case Enumeration::DbType::Int32:
                    ptr = &_int32;
                    break;
                case Enumeration::DbType::Int64:
                    ptr = &_int64;
                    break;
                case Enumeration::DbType::UInt16:
                    ptr = &_uint16;
                    break;
                case Enumeration::DbType::UInt32:
                    ptr = &_uint32;
                    break;
                case Enumeration::DbType::UInt64:
                    ptr = &_uint64;
                    break;
                case Enumeration::DbType::Double:
                    ptr = &_double;
                    break;
                case Enumeration::DbType::Float:
                    ptr = &_float;
                    break;
                case Enumeration::DbType::String:
                    ptr = &_string;
                    break;
                case Enumeration::DbType::Currency:
                    throw Exception::NonSupportedDataTypeException();
            }
        }
    }
}