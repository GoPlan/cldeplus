//
// Created by LE, Duc Anh on 5/26/15.
//

#include <Foundation/EntityMap.h>
#include <Foundation/Query/Predicate.h>
#include <Foundation/Query/Comparative.h>
#include "SqlGenerator.h"

using namespace std;

namespace Cloude {
    namespace Foundation {
        namespace Query {

            std::string CreateGetPreparedQuery(const EntityMap &entityMap,
                                               std::function<std::string(const SPtrColumn &column,
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

                int index = 0;

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&](const std::shared_ptr<Column> &column) {

                                  if (index != 0) {
                                      strCondition += " AND ";
                                  }

                                  strCondition += F(column, index);

                                  ++index;
                              });

                std::string strQuery;

                strQuery += " SELECT " + strColumns;
                strQuery += " FROM " + strTableName;
                strQuery += " WHERE " + strCondition;

                return strQuery;
            }

            std::string CreateInsertPreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const SPtrColumn &column,
                                                                            int position)> F) {

                auto const &columnsForKey = entityMap.getColumnsForKey();

                std::string strColumns;
                std::string strCondition;
                std::string strQuery;

                int index = 0;

                std::for_each(columnsForKey.cbegin(),
                              columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (index != 0) {
                                      strColumns += ", ";
                                      strCondition += ", ";
                                  }

                                  strColumns += column->getDatasourceName();
                                  strCondition += F(column, index);

                                  ++index;
                              });

                strQuery += " INSERT INTO " + entityMap.TableName() + " (" + strColumns + ")";
                strQuery += " VALUES (" + strCondition + ")";

                return strQuery;
            }

            std::string CreateUpdatePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const SPtrColumn &column,
                                                                            int index)> F) {

                auto const &columnsForUpdate = entityMap.getColumnsForUpdate();
                auto const &columnsForKey = entityMap.getColumnsForKey();

                std::string strColumns;
                std::string strCondition;
                std::string strQuery;

                int index = 0;

                bool isSetStart = true;
                bool isWhereStart = true;

                std::for_each(columnsForUpdate.cbegin(), columnsForUpdate.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (!isSetStart) {
                                      strColumns += ", ";

                                  } else {
                                      isSetStart = false;
                                  }

                                  strColumns += F(column, index);

                                  ++index;
                              });

                std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                              [&](const shared_ptr<Column> &column) -> void {

                                  if (!isWhereStart) {
                                      strCondition += ", ";
                                  } else {
                                      isWhereStart = false;
                                  }

                                  strCondition += F(column, index);

                                  ++index;
                              });

                strQuery += " UPDATE " + entityMap.TableName();
                strQuery += " SET " + strColumns;
                strQuery += " WHERE (" + strCondition + ")";

                return strQuery;
            }

            std::string CreateDeletePreparedQuery(const EntityMap &entityMap,
                                                  std::function<std::string(const SPtrColumn &column,
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

                                  ++i;
                              });

                strQuery += " DELETE FROM " + entityMap.TableName();
                strQuery += " WHERE (" + strCondition + ")";

                return strQuery;
            }

            SelectCompound CreateSelectPreparedQuery(const EntityMap &entityMap,
                                                     const Predicate &predicate,
                                                     std::function<std::string(const SPtrColumn &column,
                                                                               int index)> F) {

                SelectCompound compound;

                auto const &columnsForSelect = entityMap.getColumnsForSelect();
                auto F1 = [](const Predicate &predicate) -> std::string {

                    std::string ret;

                    switch (predicate.getComparativeType()) {
                        case Foundation::Query::Enumeration::ComparativeType::And: {
                            break;
                        }
                        case Foundation::Query::Enumeration::ComparativeType::Or: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::Like: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::NotLike: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::IsNull: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::IsNotNull: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::Equal: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::NotEqual: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::Greater: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::GreaterOrEqual: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::Lesser: {
                            break;
                        };
                        case Foundation::Query::Enumeration::ComparativeType::LesserOrEqual: {
                            break;
                        };
                    }

                    return ret;
                };


                // Prepare Columns segment
                std::string strColumns;
                strColumns.reserve(50);

                std::for_each(columnsForSelect.cbegin(), columnsForSelect.cend(),
                              [&strColumns](const std::shared_ptr<Column> &p) {
                                  if (strColumns.length() != 0)
                                      strColumns += ", ";

                                  strColumns += p->getDatasourceName();
                              });

                strColumns.shrink_to_fit();


                // Prepare Conditions segment
                std::string strCondition;
                strCondition.reserve(50);

                int index = 0;


                strCondition.shrink_to_fit();


                compound.statement += " SELECT " + strColumns;
                compound.statement += " FROM " + entityMap.TableName();
                compound.statement += " WHERE " + strCondition;

                return compound;
            }
        }
    }
}
