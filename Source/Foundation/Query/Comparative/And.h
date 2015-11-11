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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H

#include "../CriteriaComposite.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class And : public Query::CriteriaComposite {

                    static ComparativeType _type;

                public:
                    And(const SPtrCriteria &lhs, const SPtrCriteria &rhs)
                            : CriteriaComposite(lhs, rhs) { }
                    And(const And &) = default;
                    And(And &&) = default;
                    And &operator=(const And &) = default;
                    And &operator=(And &&) = default;
                    ~And() = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_AND_H
