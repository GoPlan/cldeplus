//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        Field::Field(shared_ptr<Column> spColumn) : _spColumn(spColumn) {
            ResetField();
        }

        Field::Field(shared_ptr<Column> spColumn, const std::string &value) : _spColumn(spColumn),
                                                                              _string(value) {

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