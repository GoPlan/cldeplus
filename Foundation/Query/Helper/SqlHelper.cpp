//
// Created by LE, Duc Anh on 5/26/15.
//

#include "PredicateHelper.h"
#include "SqlHelper.h"
#include <Foundation/Query/Contract/IPredicateFormatter.h>
#include <Foundation/EntityMap.h>
#include <Foundation/Query/Comparative.h>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Helper {

                std::string SqlHelper::CreateGetPreparedQuery(const EntityMap &entityMap,
                                                              FPtrParamProcessor fptr) {

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

                                      strCondition += fptr(column, index);

                                      ++index;
                                  });

                    std::string strQuery;

                    strQuery += " SELECT " + strColumns;
                    strQuery += " FROM " + strTableName;
                    strQuery += " WHERE " + strCondition;

                    return strQuery;
                }

                std::string SqlHelper::CreateInsertPreparedQuery(const EntityMap &entityMap,
                                                                 FPtrParamProcessor fptr) {

                    auto const &columnsForKey = entityMap.getColumnsForKey();

                    std::string strColumns;
                    std::string strCondition;
                    std::string strQuery;

                    int index = 0;

                    std::for_each(columnsForKey.cbegin(),
                                  columnsForKey.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (index != 0) {
                                          strColumns += ", ";
                                          strCondition += ", ";
                                      }

                                      strColumns += column->getDatasourceName();
                                      strCondition += fptr(column, index);

                                      ++index;
                                  });

                    strQuery += " INSERT INTO " + entityMap.TableName() + " (" + strColumns + ")";
                    strQuery += " VALUES (" + strCondition + ")";

                    return strQuery;
                }

                std::string SqlHelper::CreateUpdatePreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr) {

                    auto const &columnsForUpdate = entityMap.getColumnsForUpdate();
                    auto const &columnsForKey = entityMap.getColumnsForKey();

                    std::string strColumns;
                    std::string strCondition;
                    std::string strQuery;

                    int index = 0;

                    bool isSetStart = true;
                    bool isWhereStart = true;

                    std::for_each(columnsForUpdate.cbegin(), columnsForUpdate.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (!isSetStart) {
                                          strColumns += ", ";

                                      } else {
                                          isSetStart = false;
                                      }

                                      strColumns += fptr(column, index);

                                      ++index;
                                  });

                    std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (!isWhereStart) {
                                          strCondition += ", ";
                                      } else {
                                          isWhereStart = false;
                                      }

                                      strCondition += fptr(column, index);

                                      ++index;
                                  });

                    strQuery += " UPDATE " + entityMap.TableName();
                    strQuery += " SET " + strColumns;
                    strQuery += " WHERE (" + strCondition + ")";

                    return strQuery;
                }

                std::string SqlHelper::CreateDeletePreparedQuery(const EntityMap &entityMap, FPtrParamProcessor fptr) {

                    auto const &columnsForKey = entityMap.getColumnsForKey();

                    std::string strCondition;
                    std::string strQuery;

                    int i = 0;

                    std::for_each(columnsForKey.cbegin(), columnsForKey.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (i != 0) {
                                          strCondition += ", ";
                                      }

                                      strCondition += fptr(column, i);

                                      ++i;
                                  });

                    strQuery += " DELETE FROM " + entityMap.TableName();
                    strQuery += " WHERE (" + strCondition + ")";

                    return strQuery;
                }

                SqlHelper::SelectCompound SqlHelper::CreateSelectPreparedQuery(const EntityMap &entityMap,
                                                                               const Predicate &predicate,
                                                                               FPtrParamProcessor fptr) {

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
}

std::string Cloude::Foundation::Query::Helper::SqlHelper::ToSqlStringCopy(const SPtrPredicate &predicate) {

    return PredicateHelper::ToStringCopy(predicate, [](const SPtrPredicate &predicate) {

        std::string condition;

        switch (predicate->getComparativeType()) {
            case Enumeration::ComparativeType::And: {
                auto pred = std::dynamic_pointer_cast<Foundation::Query::Comparative::And>(predicate);
                condition = "(" + ToSqlStringCopy(pred->getLhs()) + ")" +
                            " AND " +
                            "(" + ToSqlStringCopy(pred->getRhs()) + ")";
                break;
            }
            case Enumeration::ComparativeType::Or: {
                auto pred = std::dynamic_pointer_cast<Foundation::Query::Comparative::Or>(predicate);
                condition = "(" + ToSqlStringCopy(pred->getLhs()) + ")" +
                            " OR " +
                            "(" + ToSqlStringCopy(pred->getLhs()) + ")";
                break;
            };
            case Enumeration::ComparativeType::Equal: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " = ";
                break;
            };
            case Enumeration::ComparativeType::NotEqual: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " != ";
                break;
            };
            case Enumeration::ComparativeType::Greater: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " > ";
                break;
            };
            case Enumeration::ComparativeType::GreaterOrEqual: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " >= ";
                break;
            };
            case Enumeration::ComparativeType::Lesser: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " < ";
                break;
            };
            case Enumeration::ComparativeType::LesserOrEqual: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " <= ";
                break;
            };
            case Enumeration::ComparativeType::Like: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " LIKE ";
                break;
            };
            case Enumeration::ComparativeType::NotLike: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " NOT LIKE ";
                break;
            };
            case Enumeration::ComparativeType::IsNull: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " IS NULL";
                break;
            };
            case Enumeration::ComparativeType::IsNotNull: {
                auto const &column = predicate->getColumn();
                condition = column.getDatasourceName() + " IS NOT NULL";
                break;
            };
        }

        if (!predicate->isComposite() &&
            (predicate->getComparativeType() !=
             Enumeration::ComparativeType::IsNull &&
             predicate->getComparativeType() !=
             Enumeration::ComparativeType::IsNotNull)) {

            auto const &value = predicate->getValue();

            switch (value->getCategory()) {
                case Type::cldeValueCategory::CharacterBased:
                    condition += "'";
                    condition += value->ToCString();
                    condition += "'";
                    break;
                default:
                    condition += value->ToCString();
                    break;
            }
        }

        return condition;
    });
}
