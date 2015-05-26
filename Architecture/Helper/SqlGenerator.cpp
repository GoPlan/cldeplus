//
// Created by LE, Duc Anh on 5/26/15.
//

#include <string>
#include "SqlGenerator.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Helper {

            std::string CreateGetPreparedQuery(const std::vector<Column> &columnsMap) {

                string strColumns;
                string strCondition;
                string strTableName;

                string strQuery;

                strQuery += " SELECT " + strColumns;
                strQuery += " FROM " + strTableName;
                strQuery += " WHERE " + strCondition;

                return strQuery;
            }
            
        }
    }
}
