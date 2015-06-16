//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

namespace Cloude {
    namespace Foundation {

        Column::Column(std::string name,
                       std::string datasourceName,
                       Type::cldeValueType dataType) : _name(name),
                                                       _datasourceName(datasourceName),
                                                       _dataType(dataType) {
            //
        }

        Column::Column(std::string name,
                       std::string datasourceName,
                       size_t length,
                       Type::cldeValueType dataType) : _name(name),
                                                       _datasourceName(datasourceName),
                                                       _length(length),
                                                       _dataType(dataType) {
            //
        }
    }
}
