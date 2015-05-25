//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"

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
    }
}