/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_SQLGENERATOR_H

#include "../../../Portable/CommonTypes.h"
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

                    static pair<string, vector<SPtrCriteria>> CreateSelectPreparedQuery
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
