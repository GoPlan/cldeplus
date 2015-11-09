//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Cell.h"
#include "Data/Helper/TypeHelper.h"
#include "Exception/CLDEEntityException.h"

namespace CLDEPlus {
    namespace Foundation {

        Cell::Cell(SPtrColumn const &column) : _column(column) {
            //
        }

        Cell::Cell(SPtrColumn const &column, Data::SPtrValue const &value) : Cell{column} {
            setValue(value);
        }

        string Cell::ToString() const {
            string result{_value->ToString() + "(" + Data::Helper::TypeHelper::CopyValueTypeToString(_value->getDataType()) + ")"};
            return result;
        }

        void Cell::setValue(Data::SPtrValue const &value) {

            if (value->getDataType() != _column->getDataType()) {
                string msg{"Value has type "
                           + Data::Helper::TypeHelper::CopyValueTypeToString(value->getDataType())
                           + " that is different with column " + _column->ToString()
                           + "(" + Data::Helper::TypeHelper::CopyValueTypeToString(_column->getDataType()) + ")"};
                throw Exception::CLDEEntityException{msg};
            }

            _value = value;
        }

        void Cell::setValue(Data::IPrimitive const &value) {
            setValue(value.ToValue());
        }
    }
}