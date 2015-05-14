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

                const string &getData_source_name() const {
                    return data_source_name;
                }

                const string &getName() const {
                    return name;
                }

                const DbType &getDb_type() const {
                    return db_type;
                }

            private:
                string data_source_name;
                string name;
                DbType db_type;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_COLUMN_H
