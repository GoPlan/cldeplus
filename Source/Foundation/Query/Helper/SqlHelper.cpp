//
// Created by LE, Duc Anh on 5/26/15.
//

#include "CriteriaHelper.h"
#include "SqlHelper.h"
#include "../../Enum/CommonBufferSize.h"
#include "../CriteriaComposite.h"
#include "../CriteriaIterator.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Helper {

                std::string SqlHelper::CreateGetPreparedQuery(const std::string &strSourceName,
                                                              const SPtrColumnVector &columnsForProjection,
                                                              const SPtrColumnVector &columnsForKey,
                                                              FPtrParamProcessor fptrProcessor) {

                    std::string strColumns;

                    std::for_each(columnsForProjection.cbegin(), columnsForProjection.cend(),
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

                                      strCondition += fptrProcessor(column, index);

                                      ++index;
                                  });

                    std::string strQuery;

                    strQuery += " SELECT " + strColumns;
                    strQuery += " FROM " + strSourceName;
                    strQuery += " WHERE " + strCondition;

                    return strQuery;
                }

                std::string SqlHelper::CreateInsertPreparedQuery(const std::string &strSourceName,
                                                                 const SPtrColumnVector &columnsForValue,
                                                                 FPtrParamProcessor fptrProcessor) {

                    std::string strColumns;
                    std::string strCondition;
                    std::string strQuery;

                    int index = 0;

                    std::for_each(columnsForValue.cbegin(),
                                  columnsForValue.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (index != 0) {
                                          strColumns += ", ";
                                          strCondition += ", ";
                                      }

                                      strColumns += column->getDatasourceName();
                                      strCondition += fptrProcessor(column, index);

                                      ++index;
                                  });

                    strQuery += " INSERT INTO " + strSourceName + " (" + strColumns + ")";
                    strQuery += " VALUES (" + strCondition + ")";

                    return strQuery;
                }

                std::string SqlHelper::CreateUpdatePreparedQuery(const std::string &strSourceName,
                                                                 const SPtrColumnVector &columnsForValue,
                                                                 const SPtrColumnVector &conditionalColumns,
                                                                 FPtrParamProcessor fptrProcessor) {

                    std::string strColumns;
                    std::string strCondition;
                    std::string strQuery;

                    int index = 0;

                    bool isSetStart = true;
                    bool isWhereStart = true;

                    std::for_each(columnsForValue.cbegin(), columnsForValue.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (!isSetStart) {
                                          strColumns += ", ";

                                      } else {
                                          isSetStart = false;
                                      }

                                      strColumns += fptrProcessor(column, index);

                                      ++index;
                                  });

                    std::for_each(conditionalColumns.cbegin(), conditionalColumns.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (!isWhereStart) {
                                          strCondition += ", ";
                                      } else {
                                          isWhereStart = false;
                                      }

                                      strCondition += fptrProcessor(column, index);

                                      ++index;
                                  });

                    strQuery += " UPDATE " + strSourceName;
                    strQuery += " SET " + strColumns;
                    strQuery += " WHERE (" + strCondition + ")";

                    return strQuery;
                }

                std::string SqlHelper::CreateDeletePreparedQuery(const std::string &strSourceName,
                                                                 const SPtrColumnVector &conditionalColumns,
                                                                 FPtrParamProcessor fptrProcessor) {

                    std::string strCondition;
                    std::string strQuery;

                    int i = 0;

                    std::for_each(conditionalColumns.cbegin(), conditionalColumns.cend(),
                                  [&](const std::shared_ptr<Column> &column) -> void {

                                      if (i != 0) {
                                          strCondition += ", ";
                                      }

                                      strCondition += fptrProcessor(column, i);

                                      ++i;
                                  });

                    strQuery += " DELETE FROM " + strSourceName;
                    strQuery += " WHERE (" + strCondition + ")";

                    return strQuery;
                }

                std::pair<std::string, std::vector<SPtrCriteria>> SqlHelper::CreateSelectPreparedQuery
                        (const std::string &strSourceName, const SPtrColumnVector &columnsForProjection,
                         const SPtrCriteria &sptrCriteria, const FPtrParamProcessor fptrParamProcessor) {

                    using PredicateComposite = Foundation::Query::CriteriaComposite;

                    /// Internal (recursive) Criteria to string copy parser lambda.
                    /// FPtrParamProcessor is forwarded from outter scope, while SPtrCriteria is not.
                    /// This forward approach is due to FPtrParamProcess does not change at (each) predicate parsing.
                    ///
                    /// Note: This lambda is RECURSIVE.
                    ///
                    std::function<std::string(const SPtrCriteria, int &)>
                            fptr = [&fptr, &fptrParamProcessor](const SPtrCriteria &fptrSPtrCriteria,
                                                                int &index) -> std::string {

                        using PredicateComposite = Foundation::Query::CriteriaComposite;

                        std::string result;
                        result.reserve(Cloude::Foundation::THIRTYTWO);

                        switch (fptrSPtrCriteria->getComparativeType()) {
                            case Cloude::Foundation::Query::ComparativeType::And: {
                                auto sptrComposite = std::dynamic_pointer_cast<PredicateComposite>(fptrSPtrCriteria);
                                result += "(" + fptr(sptrComposite->getLhs(), index) + ")";
                                result += " AND ";
                                result += "(" + fptr(sptrComposite->getRhs(), index) + ")";
                                break;
                            }
                            case Cloude::Foundation::Query::ComparativeType::Or: {
                                auto sptrComposite = std::dynamic_pointer_cast<PredicateComposite>(fptrSPtrCriteria);
                                result += "(" + fptr(sptrComposite->getLhs(), index) + ")";
                                result += " OR ";
                                result += "(" + fptr(sptrComposite->getRhs(), index) + ")";
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::Like: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " LIKE ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::NotLike: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " NOT LIKE ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::IsNull: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " IS NULL ";
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::IsNotNull: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " IS NOT NULL ";
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::Equal: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " = ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::NotEqual: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " != ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::Greater: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " > ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::GreaterOrEqual: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " >= ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::Lesser: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " < ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case Cloude::Foundation::Query::ComparativeType::LesserOrEqual: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " <= ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                        }

                        return result;
                    };

                    std::string statement;
                    std::vector<SPtrCriteria> values;

                    // Prepare Columns segment
                    std::string strColumns;
                    strColumns.reserve(Foundation::CommonBufferSize::EIGHTY);

                    std::for_each(columnsForProjection.cbegin(), columnsForProjection.cend(),
                                  [&strColumns](const std::shared_ptr<Column> &p) {
                                      if (strColumns.length() != 0)
                                          strColumns += ", ";

                                      strColumns += p->getDatasourceName();
                                  });

                    strColumns.shrink_to_fit();

                    // Prepare Conditions segment
                    int x = 0;
                    std::string strCondition = fptr(sptrCriteria, x);
                    strCondition.reserve(Foundation::CommonBufferSize::EIGHTY);

                    int y = 0;
                    SPtrCriteriaIterator iter(new CriteriaIterator(sptrCriteria));
                    while (iter) {

                        if (!iter->isVisited() && iter->isLeaf()) {
                            values.push_back(iter->getPredicate());
                            ++y;
                        }

                        iter = iter->operator++();
                    }

                    strCondition.shrink_to_fit();

                    statement += " SELECT " + strColumns;
                    statement += " FROM " + strSourceName;
                    statement += " WHERE " + strCondition;

                    return std::make_pair(statement, values);
                }

            }
        }
    }
}

