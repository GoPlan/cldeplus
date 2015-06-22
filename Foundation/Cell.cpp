//
// Created by LE, Duc Anh on 14/05/2015.
//

#include <stdexcept>
#include "Cell.h"

namespace Cloude {
    namespace Foundation {

        Cell::Cell(const SPtrColumn &column) : _column(column) {
            //
        }

        Cell::Cell(const SPtrColumn &column, const Type::SPtrValue &value) : Cell{column} {
            setValue(value);
        }

        const std::string Cell::CopyToString() const {
            std::string result{_value->ToString() + "(" + Type::cldeType::CopyToString(_value->getDataType()) + ")"};
            return result;
        }

        const std::string &Cell::ToString() const {
            return _value->ToString();
        }

        const char *Cell::ToCString() const {
            return _value->ToCString();
        }

        void Cell::setValue(const Type::SPtrValue &value) {

            if (value->getDataType() != _column->getDataType()) {
                std::string msg{"Value has type " + Type::cldeType::CopyToString(value->getDataType()) + " " +
                                "that is different with column " + _column->ToString() +
                                "(" + Type::cldeType::CopyToString(_column->getDataType()) + ")"};

                throw std::invalid_argument{msg};
            }

            _value = value;
        }
    }
}