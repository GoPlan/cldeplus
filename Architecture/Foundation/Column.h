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
                Column(const std::string name,
                       const std::string datasourceName,
                       DbType dbtype);

                virtual ~Column();

                const std::string &getDatasourceName() const {
                    return _datasourceName;
                }

                const std::string &getName() const {
                    return _name;
                }

                const DbType &getDbType() const {
                    return _dbType;
                }

            private:
                std::string _datasourceName;
                std::string _name;
                DbType _dbType;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
