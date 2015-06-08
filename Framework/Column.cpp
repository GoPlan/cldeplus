//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

using namespace Cloude::Framework::Enumeration;

namespace Cloude {
    namespace Framework {

        Column::Column(std::string name,
                       std::string datasourceName,
                       DbType dbtype) : _name(name),
                                        _datasourceName(datasourceName),
                                        _dbType(dbtype) {
            //
        }

        Column::Column(std::string name,
                       std::string datasourceName,
                       size_t length,
                       DbType dbtype) : _name(name),
                                        _datasourceName(datasourceName),
                                        _length(length),
                                        _dbType(dbtype) {
            //
        }

        void *Column::PointerToLengthVariable() {
            return &_length;
        }
    }
}
