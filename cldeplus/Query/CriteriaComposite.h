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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIACOMPOSITE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIACOMPOSITE_H

#include "cldeNonSupportedFunctionException.h"
#include "Criteria.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            class CriteriaComposite : public Criteria {

                SPtrCriteria _sptrRhs;
                SPtrCriteria _sptrLhs;

            public:
                CriteriaComposite(const SPtrCriteria &lhs, const SPtrCriteria &rhs)
                        : _sptrLhs(lhs), _sptrRhs(rhs) { };

                CriteriaComposite(const CriteriaComposite &) = default;
                CriteriaComposite(CriteriaComposite &&) = default;
                CriteriaComposite &operator=(const CriteriaComposite &) = default;
                CriteriaComposite &operator=(CriteriaComposite &&) = default;
                virtual ~CriteriaComposite() = default;

                // Criteria
                virtual const bool isComposite() const override { return true; };
                virtual const ComparativeType &getComparativeType() const override;
                virtual const SPtrColumn &getColumn() const override;
                virtual const Data::SPtrValue &getValue() const override;

                // Locals
                const SPtrCriteria &getRhs() const { return _sptrRhs; }
                const SPtrCriteria &getLhs() const { return _sptrLhs; }
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIACOMPOSITE_H
