//
// Created by GoPlan on 14/05/2015.
//

#include <iostream>
#include "Field.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Field::Field(Column &column) :
                    _column(column) {
                ResetField();
            }

            Field::~Field() {
                std::cout << "Destructor of Field: " << column().name() << " " << this << endl;
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
}