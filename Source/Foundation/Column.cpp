//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Data/Helper/TypeHelper.h"
#include "Column.h"

namespace Cloude {
    namespace Foundation {


        Column::Column(std::string name, Data::ValueType dataType)
                : _name{name}, _dataType{dataType} {
            //
        }

        Column::Column(std::string name, std::string datasourceName, Data::ValueType dataType, size_t length)
                : _name{name}, _datasourceName{datasourceName}, _length{length}, _dataType{dataType} {
            //
        }

        std::string Column::ToString() const {
            std::string result{_name + "(" + Data::Helper::TypeHelper::CopyValueTypeToString(_dataType) +
                               "[" + std::to_string(_length) + "]" + ")"};
            return result;
        }

        SPtrColumn CreateColumn(const std::string &name, Data::ValueType dataType) {
            return std::make_shared<Column>(name, dataType);
        }

        SPtrColumn CreateColumn(const std::string &name, const std::string &datasourceName, Data::ValueType dataType) {
            return std::make_shared<Column>(name, datasourceName, dataType);
        }

        SPtrColumn CreateColumn(const std::string &name,
                                const std::string &datasourceName,
                                Data::ValueType dataType,
                                size_t length) {
            return std::make_shared<Column>(name, datasourceName, dataType, length);
        }
    }
}
