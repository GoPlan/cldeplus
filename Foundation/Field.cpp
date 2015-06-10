//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"
#include "Exception/cldeNonSupportedDataTypeException.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

        Field::Field(const shared_ptr<Column> &column) : _column(column) {
            ResetField();
        }

        void Field::ResetField() {
            _int64 = 0;
        }

        void *Field::PointerToFieldValue() {
            switch (_column->getDataType()) {
                case Data::cldeValueType::Int64:
                    return &_int64;
                case Data::cldeValueType::Varchar:
                    return &_cstr;
                default:
                    throw Exception::cldeNonSupportedDataTypeException();
            }
        }
    }
}