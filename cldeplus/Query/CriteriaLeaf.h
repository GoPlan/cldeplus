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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIALEAF_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIALEAF_H

#include "Criteria.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            class CriteriaLeaf : public Criteria {

                SPtrColumn _column;
                Data::SPtrValue _value;

            public:
                CriteriaLeaf(const SPtrColumn &column, const Data::SPtrValue &value)
                        : _column(column), _value(value) { };

                CriteriaLeaf(const CriteriaLeaf &) = default;
                CriteriaLeaf(CriteriaLeaf &&) = default;
                CriteriaLeaf &operator=(const CriteriaLeaf &) = default;
                CriteriaLeaf &operator=(CriteriaLeaf &&) = default;
                virtual ~CriteriaLeaf() = default;

                // Criteria
                virtual const bool isComposite() const override;
                virtual const SPtrColumn &getColumn() const override;
                virtual const Data::SPtrValue &getValue() const override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIALEAF_H
