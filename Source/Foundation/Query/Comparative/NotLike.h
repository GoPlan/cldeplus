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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTLIKE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTLIKE_H

#include "../CriteriaLeaf.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class NotLike : public CriteriaLeaf {

                    static ComparativeType _type;

                public:
                    NotLike(const SPtrColumn &column, const Data::SPtrValue &value) : CriteriaLeaf(column, value) { };
                    NotLike(const NotLike &) = default;
                    NotLike(NotLike &&) = default;
                    NotLike &operator=(const NotLike &) = default;
                    NotLike &operator=(NotLike &) = default;
                    ~NotLike() = default;

                    // Criteria
                    const ComparativeType &getComparativeType() const override { return _type; };
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_NOTLIKE_H
