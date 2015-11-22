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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H

#include "../CriteriaLeaf.h"
#include "cldeNonSupportedFunctionException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                class IsNull : public Criteria {

                    SPtrColumn _column;
                    static ComparativeType _type;

                public:
                    IsNull(const SPtrColumn &column) : _column(column) { };
                    IsNull(const IsNull &) = default;
                    IsNull(IsNull &&) = default;
                    IsNull &operator=(const IsNull &) = default;
                    IsNull &operator=(IsNull &&) = default;
                    ~IsNull() = default;

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

#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_ISNULL_H
