//
// Created by LE, Duc Anh on 5/26/15.
//
#include "memory"
#include "SqlGenerator.h"

using namespace std;

namespace Cloude {
    namespace Foundation {
        namespace Helper {

            std::string CreateGetPreparedQuery(const EntityMap &entityMap,
                                               std::function<std::string(const std::shared_ptr<Column> &column,
                                                                         int position)> F) {

                auto const &columnsForGet = entityMap.getColumnsForGet();
                auto const &columnsForKey = entityMap.getColumnsForKey();

                std::string strTableName = entityMap.TableName();
                std::string strColumns;

                std::for_each(columnsForGet.cbegin(), columnsForGet.cend(),
                              [&strColumns](const std::shared_ptr<Column> &p) {
                                  if (strColumns.length() != 0)
                                      strColumns += ", ";

                                  strColumns += p->getDatasourceName();
                              });


                std::string strCondition;

                int i = 0;

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&](const std::shared_ptr<Column> &column) {

                                  if (i != 0) {
                                      strCondition += " AND ";
                                  }

                                  strCondition += F(column, i);

                                  i++;
                              });

                std::string strQuery;

                strQuery += " SELECT " + strColumns;
                strQuery += " FROM " + strTableName;
                strQuery += " WHERE " + strCondition;

                return strQuery;
            }

            std::string CreateInsertPreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            int position)> F) {

                auto const &columnsForKey = entityMap.getColumnsForKey();

                std::string strColumns;
                std::string strCondition;
                std::string strQuery;

                int i = 0;

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (i != 0) {
                                      strColumns += ", ";
                                      strCondition += ", ";
                                  }

                                  strColumns += column->getDatasourceName();
                                  strCondition += F(column, i);

                              });

                strQuery += " INSERT INTO " + entityMap.TableName() + " (" + strColumns + ")";
                strQuery += " VALUES (" + strCondition + ")";

                return strQuery;
            }

            std::string CreateUpdatePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            int index)> F) {

                auto const &columnsForUpdate = entityMap.getColumnsForUpdate();
                auto const &columnsForKey = entityMap.getColumnsForKey();

                std::string strColumns;
                std::string strCondition;
                std::string strQuery;

                int x = 0;

                bool isSetStart = true;
                bool isWhereStart = true;

                std::for_each(columnsForUpdate.cbegin(), columnsForUpdate.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (!isSetStart) {
                                      strColumns += ", ";

                                  } else {
                                      isSetStart = false;
                                  }

                                  strColumns += F(column, x);

                                  x++;
                              });

                std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (!isWhereStart) {
                                      strCondition += ", ";
                                  } else {
                                      isWhereStart = false;
                                  }

                                  strCondition += F(column, x);

                                  x++;
                              });

                strQuery += " UPDATE " + entityMap.TableName();
                strQuery += " SET " + strColumns;
                strQuery += " WHERE (" + strCondition + ")";

                return strQuery;
            }

            std::string CreateDeletePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            int index)> F) {
                auto const &columnsForKey = entityMap.getColumnsForKey();

                std::string strCondition;
                std::string strQuery;

                int i = 0;

                std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (i != 0) {
                                      strCondition += ", ";
                                  }

                                  strCondition += F(column, i);

                              });

                strQuery += " DELETE FROM " + entityMap.TableName();
                strQuery += " WHERE (" + strCondition + ")";

                return strQuery;
            }

            std::string CreateSelectPreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const std::shared_ptr<Column> &column,
                                                                            int index)> F) {

                auto const &columnsForSelect = entityMap.getColumnsForSelect();
                auto const &columnsForKey = entityMap.getColumnsForKey();

                std::string strTableName = entityMap.TableName();
                std::string strColumns;

                std::for_each(columnsForSelect.cbegin(), columnsForSelect.cend(),
                              [&strColumns](const std::shared_ptr<Column> &p) {
                                  if (strColumns.length() != 0)
                                      strColumns += ", ";

                                  strColumns += p->getDatasourceName();
                              });

                std::string strCondition;

                int i = 0;

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&](const std::shared_ptr<Column> &column) {

                                  if (i != 0) {
                                      strCondition += " AND ";
                                  }

                                  strCondition += F(column, i);

                                  i++;
                              });

                std::string strQuery;

                strQuery += " SELECT " + strColumns;
                strQuery += " FROM " + strTableName;
                strQuery += " WHERE " + strCondition;

                return strQuery;
            }
        }
    }
}
