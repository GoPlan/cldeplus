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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H

#include "../Criteria.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class IsNotNull : public Criteria {

                    SPtrColumn _column;
                    static ComparativeType _type;

                public:
                    IsNotNull(const SPtrColumn &column) : _column(column) { };
                    IsNotNull(const IsNotNull &) = default;
                    IsNotNull(IsNotNull &&) = default;
                    IsNotNull &operator=(const IsNotNull &) = default;
                    IsNotNull &operator=(IsNotNull &&) = default;
                    ~IsNotNull() = default;

                    // CriteriaLeaf
                    const SPtrColumn &getColumn() const override;
                    const bool isComposite() const override;
                    const ComparativeType &getComparativeType() const override;
                    const Data::SPtrValue &getValue() const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNOTNULL_H
