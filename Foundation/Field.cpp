//
// Created by LE, Duc Anh on 14/05/2015.
//

#include <stdexcept>
#include "Field.h"

namespace Cloude {
    namespace Foundation {

        Field::Field(const SPtrColumn &column) : _column(column) {
            //
        }

        Field::Field(const SPtrColumn &column, const Type::SPtrValue &value) : Field{column} {
            setValue(value);
        }

        const std::string Field::CopyToString() const {
            std::string result{_value->ToString() + "(" + Type::cldeType::CopyToString(_value->getDataType()) + ")"};
            return result;
        }

        const std::string &Field::ToString() const {
            return _value->ToString();
        }

        const char *Field::ToCString() const {
            return _value->ToCString();
        }

        void Field::setValue(const Type::SPtrValue &value) {

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