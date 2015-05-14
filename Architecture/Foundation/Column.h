//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_COLUMN_H
#define CLOUD_E_CPLUS_COLUMN_H

#include <string>
#include "../Enumeration/DbType.h"

using namespace std;
using namespace Cloude::Architecture::Enumeration;

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Column {

            public:

                Column(string name, string dataSourceName, DbType dbType);

                virtual ~Column();
                
                const string &getDataSourceName() const {
                    return dataSourceName;
                }

                const string &getName() const {
                    return name;
                }

                const DbType &getDbType() const {
                    return dbType;
                }

            private:
                string dataSourceName;
                string name;
                DbType dbType;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
