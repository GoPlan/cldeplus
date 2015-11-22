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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H

#include <string>
#include <functional>
#include "../Criteria.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            namespace Contract {
                class IPredicateFormatter;
            }

            namespace Helper {
                struct CriteriaHelper {
                    using FPtrProcessor = std::function<string(const SPtrCriteria &)>;
                    static string CopyToString(const SPtrCriteria &sptrCriteria, const Contract::IPredicateFormatter &formatter);
                    static string CopyToString(const SPtrCriteria &sptrCriteria, const FPtrProcessor fptrProcessor);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
