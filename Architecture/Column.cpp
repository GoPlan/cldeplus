//
// Created by GoPlan on 14/05/2015.
//

#include "Column.h"

using namespace Cloude::Architecture::Enumeration;

namespace Cloude {
    namespace Architecture {

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


        void Column::AssignLengthPointer(void *ptr) {
            ptr = &_length;
        }
    }
}
