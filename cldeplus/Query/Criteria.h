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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H

#include "Portable.h"
#include "EntityColumn.h"
#include "../Data/Value.h"
#include "../Query/ComparativeType.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            class Criteria : public std::enable_shared_from_this<Criteria> {

            public:
                Criteria() = default;
                Criteria(const Criteria &) = default;
                Criteria(Criteria &&) = default;
                Criteria &operator=(const Criteria &) = default;
                Criteria &operator=(Criteria &&) = default;
                ~Criteria() = default;

                virtual const bool isComposite() const = 0;
                virtual const SPtrColumn &getColumn() const = 0;
                virtual const ComparativeType &getComparativeType() const = 0;
                virtual const Data::SPtrValue &getValue() const = 0;
            };

            using SPtrCriteria = shared_ptr<Criteria>;
            using WPtrCriteria = std::weak_ptr<Criteria>;
            using SPtrCriteriaVector = vector<SPtrCriteria>;
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CRITERIA_H
