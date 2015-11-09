//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Cell.h"
#include "Data/Helper/TypeHelper.h"
#include "Data/ValueFactory.h"
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

        void Cell::setValue(int16 value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateInt16(value);
            }
        }

        void Cell::setValue(int32 value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateInt(value);
            }
        }

        void Cell::setValue(int64 value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateInt64(value);
            }
        }

        void Cell::setValue(uint16 value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateUInt16(value);
            }
        }

        void Cell::setValue(uint32 value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateUInt32(value);
            }
        }

        void Cell::setValue(uint64 value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateUInt64(value);
            }
        }

        void Cell::setValue(float value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateFloat(value);
            }
        }

        void Cell::setValue(double value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateDouble(value);
            }
        }

        void Cell::setValue(bool value) {
            if (_value) {
                _value->operator=(value);
            }
            else {
                _value = Data::ValueFactory::CreateBoolean(value);
            }
        }
    }
}