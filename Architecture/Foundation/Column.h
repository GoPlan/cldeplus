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
                Column(string name, string datasourceName, DbType dbtype);
                virtual ~Column();

                const string &getDatasourceName() const {
                    return datasourceName;
                }
                const string &getName() const {
                    return name;
                }
                const DbType &getDataType() const {
                    return dataType;
                }

            private:
                string datasourceName;
                string name;
                DbType dataType;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
