//
// Created by LE, Duc Anh on 14/05/2015.
//

#include <stdexcept>
#include <Foundation/Data/Helper/TypeHelper.h>
#include "Cell.h"

namespace Cloude {
    namespace Foundation {

        Cell::Cell(const SPtrColumn &column) : _column(column) {
            //
        }

        Cell::Cell(const SPtrColumn &column, const Data::SPtrValue &value) : Cell{column} {
            setValue(value);
        }

        std::string Cell::ToString() const {
            std::string result{_value->ToString() +
                               "(" + Data::Helper::TypeHelper::CopyToString(_value->getDataType()) + ")"};
            return result;
        }

        void Cell::setValue(const Data::SPtrValue &value) {

            if (value->getDataType() != _column->getDataType()) {
                std::string msg{"Value has type " + Data::Helper::TypeHelper::CopyToString(value->getDataType()) + " " +
                                "that is different with column " + _column->ToString() +
                                "(" + Data::Helper::TypeHelper::CopyToString(_column->getDataType()) + ")"};

                throw std::invalid_argument{msg};
            }

            _value = value;
        }
    }
}