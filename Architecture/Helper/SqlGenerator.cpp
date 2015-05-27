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

                auto columnsMap = entityMap.getColumnsMap();
                auto columnsForKey = entityMap.getColumnsForKey();

                std::string strColumns;
                std::string strTableName = entityMap.TableName();
                std::string strCondition;

                std::for_each(columnsMap.cbegin(), columnsMap.cend(),
                              [&strColumns](const std::pair<string, std::shared_ptr<Column>> p) {
                                  auto spColumn = p.second;

                                  if (strColumns.length() != 0)
                                      strColumns += ", ";

                                  strColumns += spColumn->getDatasourceName();
                              });

                std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                              [&strCondition](const std::shared_ptr<Column> &c) {

                                  if (strCondition.length() != 0)
                                      strCondition += ", ";

                                  strCondition += c->getDatasourceName() + " = ?";
                              });

                std::string strQuery;

                strQuery += " SELECT (" + strColumns + ")";
                strQuery += " FROM " + strTableName;
                strQuery += " WHERE (" + strCondition + ")";

                return strQuery;
            }

        }
    }
}
