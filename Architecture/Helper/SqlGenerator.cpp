//
// Created by LE, Duc Anh on 5/26/15.
//
#include "memory"
#include "SqlGenerator.h"
#include "Architecture/Column.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Helper {

            std::string CreateGetPreparedQuery(EntityMap &entityMap) {
                return CreateGetPreparedQuery(entityMap, [](const std::string &column,
                                                            const std::string &prefix,
                                                            const std::string &suffix,
                                                            const int &position) -> std::string {

                    std::string condition = prefix + column + suffix + " = ?";

                    return condition;
                });
            }

            std::string CreateGetPreparedQuery(EntityMap &entityMap,
                                               std::function<std::string(const std::string &column,
                                                                         const std::string &prefix,
                                                                         const std::string &suffix,
                                                                         const int &position)> F) {

                auto columnsMap = entityMap.getColumnsForGet();
                auto columnsForKey = entityMap.getColumnsForKey();


                std::string strTableName = entityMap.TableName();
                std::string strColumns;

                std::for_each(columnsMap.cbegin(), columnsMap.cend(),
                              [&strColumns](const std::shared_ptr<Column>& p) {
                                  if (strColumns.length() != 0)
                                      strColumns += ", ";

                                  strColumns += p->getDatasourceName();
                              });


                std::string strCondition;
                std::string strConditionPrefix;
                std::string strConditionSuffix;

                int index = 1;

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&](const std::shared_ptr<Column> &c) {

                                  if (strCondition.length() != 0)
                                      strCondition += " AND ";

                                  strCondition += F(c->getDatasourceName(),
                                                    strConditionPrefix,
                                                    strConditionSuffix,
                                                    index);

                                  index++;
                              });

                std::string strQuery;

                strQuery += " SELECT " + strColumns + "";
                strQuery += " FROM " + strTableName;
//                strQuery += " WHERE (" + strCondition + ")";
                strQuery += " WHERE (id = 6)";

                return strQuery;
            }
        }
    }
}
