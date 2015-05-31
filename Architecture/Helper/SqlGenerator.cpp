//
// Created by LE, Duc Anh on 5/26/15.
//
#include "memory"
#include "SqlGenerator.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Helper {

            std::string CreateGetPreparedQuery(const EntityMap &entityMap) {

                auto F = [](const std::string &column,
                            const std::string &prefix,
                            const std::string &suffix,
                            const int &position) -> std::string {

                    std::string condition = column + " = ?";

                    return condition;
                };

                return CreateGetPreparedQuery(entityMap, F);
            }

            std::string CreateGetPreparedQuery(const EntityMap &entityMap,
                                               std::function<std::string(const std::string &column,
                                                                         const std::string &prefix,
                                                                         const std::string &suffix,
                                                                         const int &position)> F) {

                auto columnsMap = entityMap.getColumnsForGet();
                auto columnsForKey = entityMap.getColumnsForKey();

                std::string strTableName = entityMap.TableName();
                std::string strColumns;

                std::for_each(columnsMap.cbegin(), columnsMap.cend(),
                              [&strColumns](const std::shared_ptr<Column> &p) {
                                  if (strColumns.length() != 0)
                                      strColumns += ", ";

                                  strColumns += p->getDatasourceName();
                              });


                std::string strCondition;
                std::string strConditionPrefix;
                std::string strConditionSuffix;

                int i = 0;

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&](const std::shared_ptr<Column> &c) {

                                  if (i != 0) {
                                      strCondition += " AND ";
                                  }

                                  strCondition += F(c->getDatasourceName(),
                                                    strConditionPrefix,
                                                    strConditionSuffix,
                                                    i);

                                  i++;
                              });

                std::string strQuery;

                strQuery += " SELECT " + strColumns;
                strQuery += " FROM " + strTableName;
                strQuery += " WHERE " + strCondition;

                return strQuery;
            }

            std::string CreateInsertPreparedQuery(const EntityMap &entityMap) {

                auto F = [](const std::string &column,
                            const std::string &prefix,
                            const std::string &suffix,
                            const int &position) -> std::string {

                    return "?";
                };

                return CreateInsertPreparedQuery(entityMap, F);
            }

            std::string CreateInsertPreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::string &column,
                                                                            const std::string &prefix,
                                                                            const std::string &suffix,
                                                                            const int &position)> F) {

                auto columnsForKey = entityMap.getColumnsForKey();

                std::string strColumns;
                std::string strCondition;
                std::string strConditionPrefix;
                std::string strConditionSuffix;
                std::string strQuery;

                int i = 0;

                std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (i != 0) {
                                      strColumns += ", ";
                                      strCondition += ", ";
                                  }

                                  strColumns += column->getDatasourceName();
                                  strCondition += F(column->getDatasourceName(),
                                                    strConditionPrefix,
                                                    strConditionSuffix,
                                                    i);

                              });

                strQuery += " INSERT INTO " + entityMap.TableName() + " (" + strColumns + ")";
                strQuery += " VALUES (" + strCondition + ")";

                return strQuery;
            }

            std::string CreateUpdatePreparedQuery(const EntityMap &entityMap) {

                auto F = [](const std::string &column,
                            const std::string &prefix,
                            const std::string &suffix,
                            const int &position) -> std::string {

                    std::string condition = column + " = ?";

                    return condition;
                };

                return CreateUpdatePreparedQuery(entityMap, F);
            }

            std::string CreateUpdatePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::string &column,
                                                                            const std::string &prefix,
                                                                            const std::string &suffix,
                                                                            const int &index)> F) {

                auto columnsForUpdate = entityMap.getColumnsForUpdate();
                auto columnsForKey = entityMap.getColumnsForKey();

                std::string strColumns;
                std::string strCondition;
                std::string strConditionPrefix;
                std::string strConditionSuffix;
                std::string strQuery;

                int x = 0;

                std::for_each(columnsForUpdate.cbegin(), columnsForUpdate.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (x != 0) {
                                      strColumns += ", ";
                                  }

                                  strColumns += F(column->getDatasourceName(),
                                                  strConditionPrefix,
                                                  strConditionSuffix,
                                                  x);

                                  x++;
                              });

                int y = 0;

                std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (y != 0) {
                                      strCondition += ", ";
                                  }

                                  strCondition += F(column->getDatasourceName(),
                                                    strConditionPrefix,
                                                    strConditionSuffix,
                                                    y);

                                  y++;
                              });

                strQuery += " UPDATE " + entityMap.TableName();
                strQuery += " SET " + strColumns;
                strQuery += " WHERE (" + strCondition + ")";

                return strQuery;
            }

            std::string CreateDeletePreparedQuery(const EntityMap &entityMap) {

                auto F = [](const std::string &column,
                            const std::string &prefix,
                            const std::string &suffix,
                            const int &position) -> std::string {

                    std::string condition = column + " = ?";

                    return condition;
                };

                return CreateDeletePreparedQuery(entityMap, F);
            }

            std::string CreateDeletePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::string &column,
                                                                            const std::string &prefix,
                                                                            const std::string &suffix,
                                                                            const int &index)> F) {
                auto columnsForKey = entityMap.getColumnsForKey();

                std::string strCondition;
                std::string strConditionPrefix;
                std::string strConditionSuffix;
                std::string strQuery;

                int i = 0;

                std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (i != 0) {
                                      strCondition += ", ";
                                  }

                                  strCondition += F(column->getDatasourceName(),
                                                    strConditionPrefix,
                                                    strConditionSuffix,
                                                    i);
                              });

                strQuery += " DELETE FROM " + entityMap.TableName();
                strQuery += " WHERE (" + strCondition + ")";

                return strQuery;
            }
        }
    }
}
