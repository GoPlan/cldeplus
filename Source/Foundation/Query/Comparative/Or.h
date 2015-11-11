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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H

#include "../../Exception/CLDENonSupportedFunctionException.h"
#include "../CriteriaComposite.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class Or : public Query::CriteriaComposite {

                    static ComparativeType _type;

                public:
                    Or(const SPtrCriteria &lhs, const SPtrCriteria &rhs)
                            : CriteriaComposite(lhs, rhs) { }
                    Or(const Or &rhs) = default;
                    Or(Or &&) = default;
                    Or &operator=(const Or &) = default;
                    Or &operator=(Or &&) = default;
                    ~Or() = default;

                    // Locals
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_OR_H
