//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H

#include <memory>
#include <vector>
#include <functional>
#include <Foundation/Query/Criteria.h>

namespace Cloude {
    namespace Foundation {

        class Column;
        class EntityMap;

        namespace Type {
            class cldeValue;
        }

        namespace Query {

            class Criteria;

            namespace Helper {

                class SqlHelper {
                    SqlHelper() = delete;
                    SqlHelper(const SqlHelper &) = delete;
                    SqlHelper(SqlHelper &&) = delete;
                    SqlHelper &operator=(const SqlHelper &) = delete;
                    SqlHelper &operator=(SqlHelper &&) = delete;

                public:
                    using FPtrParamProcessor = std::function<std::string(const SPtrColumn &column, const int &index)>;

                public:
                    static std::string CreateGetPreparedQuery(const std::string &strSourceName,
                                                              const SPtrColumnVector &columnsForProjection,
                                                              const SPtrColumnVector &columnsForKey,
                                                              FPtrParamProcessor fptrProcessor);

                    static std::string CreateInsertPreparedQuery(const std::string &strSourceName,
                                                                 const SPtrColumnVector &columnsForValue,
                                                                 FPtrParamProcessor fptrProcessor);

                    static std::string CreateUpdatePreparedQuery(const std::string &strSourceName,
                                                                 const SPtrColumnVector &columnsForValue,
                                                                 const SPtrColumnVector &conditionalColumns,
                                                                 FPtrParamProcessor fptrProcessor);

                    static std::string CreateDeletePreparedQuery(const std::string &strSourceName,
                                                                 const SPtrColumnVector &conditionalColumns,
                                                                 FPtrParamProcessor fptrProcessor);

                    static std::pair<std::string, std::vector<SPtrCriteria>> CreateSelectPreparedQuery
                            (const std::string &strSourceName,
                             const SPtrColumnVector &columnsForProjection,
                             const SPtrCriteria &sptrCriteria,
                             const FPtrParamProcessor fptrProcessor);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
