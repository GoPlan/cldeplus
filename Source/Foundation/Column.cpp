//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Data/Helper/TypeHelper.h"
#include "Column.h"

namespace CLDEPlus {
    namespace Foundation {


        Column::Column(string name, Data::ValueType dataType)
                : _name{name}, _dataType{dataType} {
            //
        }

        Column::Column(string name, Data::ValueType dataType, string datasourceName, size_t length)
                : _name{name}, _datasourceName{datasourceName}, _length{length}, _dataType{dataType} {
            //
        }

        string Column::ToString() const {
            string result{_name + "(" + Data::Helper::TypeHelper::CopyValueTypeToString(_dataType) +
                          "[" + std::to_string(_length) + "]" + ")"};
            return result;
        }

        SPtrColumn CreateColumn(string const &name, Data::ValueType dataType) {
            return cldeplus_make_shared<Column>(name, dataType);
        }

        SPtrColumn CreateColumn(string const &name, Data::ValueType dataType, string const &datasourceName,
                                size_t length) {
            return cldeplus_make_shared<Column>(name, dataType, datasourceName, length);
        }
    }
}
