//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H

#include "cldeplus_default"
#include "../Criteria.h"

namespace CLDEPlus {
    namespace Foundation {

        class Column;
        class EntityMap;

        namespace Data {
            class Value;
        }

        namespace Query {

            class Criteria;

            namespace Helper {

                struct SqlHelper {

                    using FPtrParamProcessor = std::function<string(const SPtrColumn &column, const int &index)>;

                    static string CreateGetPreparedQuery
                            (const string &strSourceName,
                             const SPtrColumnVector &columnsForProjection,
                             const SPtrColumnVector &columnsForKey,
                             FPtrParamProcessor fptrProcessor);

                    static string CreateInsertPreparedQuery
                            (const string &strSourceName,
                             const SPtrColumnVector &columnsForValue,
                             FPtrParamProcessor fptrProcessor);

                    static string CreateUpdatePreparedQuery
                            (const string &strSourceName,
                             const SPtrColumnVector &columnsForValue,
                             const SPtrColumnVector &conditionalColumns,
                             FPtrParamProcessor fptrProcessor);

                    static string CreateDeletePreparedQuery
                            (const string &strSourceName,
                             const SPtrColumnVector &conditionalColumns,
                             FPtrParamProcessor fptrProcessor);

                    static std::pair<string, vector<SPtrCriteria>> CreateSelectPreparedQuery
                            (const string &strSourceName,
                             const SPtrColumnVector &columnsForProjection,
                             const SPtrCriteria &sptrCriteria,
                             const FPtrParamProcessor fptrProcessor);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
