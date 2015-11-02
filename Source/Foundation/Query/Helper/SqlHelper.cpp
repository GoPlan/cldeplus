//
// Created by LE, Duc Anh on 5/26/15.
//

#include "CriteriaHelper.h"
#include "SqlHelper.h"
#include "../../Enum/CommonBufferSize.h"
#include "../CriteriaComposite.h"
#include "../CriteriaIterator.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Helper {

                string SqlHelper::CreateGetPreparedQuery(const string &strSourceName,
                                                              const SPtrColumnVector &columnsForProjection,
                                                              const SPtrColumnVector &columnsForKey,
                                                              FPtrParamProcessor fptrProcessor) {

                    string strColumns;

                    std::for_each(columnsForProjection.cbegin(), columnsForProjection.cend(),
                                  [&strColumns](const shared_ptr<Column> &p) {
                                      if (strColumns.length() != 0)
                                          strColumns += ", ";

                                      strColumns += p->getDatasourceName();
                                  });


                    string strCondition;

                    int index = 0;

                    std::for_each(columnsForKey.cbegin(),
                                  columnsForKey.cend(),
                                  [&](const shared_ptr<Column> &column) {

                                      if (index != 0) {
                                          strCondition += " AND ";
                                      }

                                      strCondition += fptrProcessor(column, index);

                                      ++index;
                                  });

                    string strQuery;

                    strQuery += " SELECT " + strColumns;
                    strQuery += " FROM " + strSourceName;
                    strQuery += " WHERE " + strCondition;

                    return strQuery;
                }

                string SqlHelper::CreateInsertPreparedQuery(const string &strSourceName,
                                                                 const SPtrColumnVector &columnsForValue,
                                                                 FPtrParamProcessor fptrProcessor) {

                    string strColumns;
                    string strCondition;
                    string strQuery;

                    int index = 0;

                    std::for_each(columnsForValue.cbegin(),
                                  columnsForValue.cend(),
                                  [&](const shared_ptr<Column> &column) -> void {

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

                string SqlHelper::CreateUpdatePreparedQuery(const string &strSourceName,
                                                                 const SPtrColumnVector &columnsForValue,
                                                                 const SPtrColumnVector &conditionalColumns,
                                                                 FPtrParamProcessor fptrProcessor) {

                    string strColumns;
                    string strCondition;
                    string strQuery;

                    int index = 0;

                    bool isSetStart = true;
                    bool isWhereStart = true;

                    std::for_each(columnsForValue.cbegin(), columnsForValue.cend(),
                                  [&](const shared_ptr<Column> &column) -> void {

                                      if (!isSetStart) {
                                          strColumns += ", ";

                                      } else {
                                          isSetStart = false;
                                      }

                                      strColumns += fptrProcessor(column, index);

                                      ++index;
                                  });

                    std::for_each(conditionalColumns.cbegin(), conditionalColumns.cend(),
                                  [&](const shared_ptr<Column> &column) -> void {

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

                string SqlHelper::CreateDeletePreparedQuery(const string &strSourceName,
                                                                 const SPtrColumnVector &conditionalColumns,
                                                                 FPtrParamProcessor fptrProcessor) {

                    string strCondition;
                    string strQuery;

                    int i = 0;

                    std::for_each(conditionalColumns.cbegin(), conditionalColumns.cend(),
                                  [&](const shared_ptr<Column> &column) -> void {

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

                std::pair<string, vector<SPtrCriteria>> SqlHelper::CreateSelectPreparedQuery
                        (const string &strSourceName, const SPtrColumnVector &columnsForProjection,
                         const SPtrCriteria &sptrCriteria, const FPtrParamProcessor fptrParamProcessor) {

                    using PredicateComposite = Foundation::Query::CriteriaComposite;

                    /// Internal (recursive) Criteria to string copy parser lambda.
                    /// FPtrParamProcessor is forwarded from outter scope, while SPtrCriteria is not.
                    /// This forward approach is due to FPtrParamProcess does not change at (each) predicate parsing.
                    ///
                    /// Note: This lambda is RECURSIVE.
                    ///
                    std::function<string(const SPtrCriteria, int &)>
                            fptr = [&fptr, &fptrParamProcessor](const SPtrCriteria &fptrSPtrCriteria,
                                                                int &index) -> string {

                        using PredicateComposite = Foundation::Query::CriteriaComposite;

                        string result;
                        result.reserve(CLDEPlus::Foundation::THIRTYTWO);

                        switch (fptrSPtrCriteria->getComparativeType()) {
                            case CLDEPlus::Foundation::Query::ComparativeType::And: {
                                auto sptrComposite = std::dynamic_pointer_cast<PredicateComposite>(fptrSPtrCriteria);
                                result += "(" + fptr(sptrComposite->getLhs(), index) + ")";
                                result += " AND ";
                                result += "(" + fptr(sptrComposite->getRhs(), index) + ")";
                                break;
                            }
                            case CLDEPlus::Foundation::Query::ComparativeType::Or: {
                                auto sptrComposite = std::dynamic_pointer_cast<PredicateComposite>(fptrSPtrCriteria);
                                result += "(" + fptr(sptrComposite->getLhs(), index) + ")";
                                result += " OR ";
                                result += "(" + fptr(sptrComposite->getRhs(), index) + ")";
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::Like: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " LIKE ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::NotLike: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " NOT LIKE ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::IsNull: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " IS NULL ";
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::IsNotNull: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " IS NOT NULL ";
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::Equal: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " = ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::NotEqual: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " != ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::Greater: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " > ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::GreaterOrEqual: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " >= ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::Lesser: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " < ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                            case CLDEPlus::Foundation::Query::ComparativeType::LesserOrEqual: {
                                result += fptrSPtrCriteria->getColumn()->getDatasourceName();
                                result += " <= ";
                                result += fptrParamProcessor(fptrSPtrCriteria->getColumn(), index);
                                ++index;
                                break;
                            };
                        }

                        return result;
                    };

                    string statement;
                    vector<SPtrCriteria> values;

                    // Prepare Columns segment
                    string strColumns;
                    strColumns.reserve(Foundation::CommonBufferSize::EIGHTY);

                    std::for_each(columnsForProjection.cbegin(), columnsForProjection.cend(),
                                  [&strColumns](const shared_ptr<Column> &p) {
                                      if (strColumns.length() != 0)
                                          strColumns += ", ";

                                      strColumns += p->getDatasourceName();
                                  });

                    strColumns.shrink_to_fit();

                    // Prepare Conditions segment
                    int x = 0;
                    string strCondition = fptr(sptrCriteria, x);
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

