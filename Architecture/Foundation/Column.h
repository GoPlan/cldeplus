//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_COLUMN_H
#define CLOUD_E_CPLUS_COLUMN_H

#include <string>
#include "../Enumeration/DbType.h"

using namespace Cloude::Architecture::Enumeration;

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Column {

            public:
                Column(std::string name, std::string datasourceName, DbType dbtype);
                virtual ~Column();

                const std::string &datasource_name() const {
                    return _datasource_name;
                }
                const std::string &name() const {
                    return _name;
                }
                const DbType &db_type() const {
                    return _db_type;
                }

            private:
                std::string _datasource_name;
                std::string _name;
                DbType _db_type;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
