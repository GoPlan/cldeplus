//
// Created by LE, Duc Anh on 14/05/2015.
//

#include <Foundation/Data/Helper/TypeHelper.h>
#include "Column.h"

namespace Cloude {
    namespace Foundation {


        Column::Column(std::string name,
                       Data::ValueType dataType) : _name{name},
                                                   _dataType{dataType} {

        }

        Column::Column(std::string name,
                       std::string datasourceName,
                       Data::ValueType dataType) : _name{name},
                                                   _datasourceName{datasourceName},
                                                   _dataType{dataType} {
            //
        }

        Column::Column(std::string name,
                       std::string datasourceName,
                       size_t length,
                       Data::ValueType dataType) : _name{name},
                                                   _datasourceName{datasourceName},
                                                   _length{length},
                                                   _dataType{dataType} {
            //
        }

        const std::string Column::CopyToString() const {
            std::string result{_name + "(" + Data::Helper::TypeHelper::CopyToString(_dataType) +
                               "[" + std::to_string(_length) + "]" + ")"};
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
