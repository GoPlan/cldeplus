//
// Created by LE, Duc Anh on 14/05/2015.
//

#include "Column.h"

namespace Cloude {
    namespace Foundation {


        Column::Column(std::string name,
                       Type::cldeValueType dataType) : _name{name},
                                                       _dataType{dataType} {

        }

        Column::Column(std::string name,
                       std::string datasourceName,
                       Type::cldeValueType dataType) : _name{name},
                                                       _datasourceName{datasourceName},
                                                       _dataType{dataType} {
            //
        }

        Column::Column(std::string name,
                       std::string datasourceName,
                       size_t length,
                       Type::cldeValueType dataType) : _name{name},
                                                       _datasourceName{datasourceName},
                                                       _length{length},
                                                       _dataType{dataType} {
            //
        }

        const std::string Column::CopyToString() const {
            std::string result{_name + "(" + Type::cldeType::CopyToString(_dataType) +
                               "[" + std::to_string(_length) + "]" +
                               ")"};
            return result;
        }
        const std::string &Column::ToString() const {
            return _name;
        }
        const char *Column::ToCString() const {
            return _name.c_str();
        }
    }
}
