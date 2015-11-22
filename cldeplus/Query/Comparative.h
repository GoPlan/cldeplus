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

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_H

#include "ComparativeType.h"
#include "Comparative/And.h"
#include "Comparative/Or.h"
#include "Comparative/Equal.h"
#include "Comparative/NotEqual.h"
#include "Comparative/Greater.h"
#include "Comparative/GreaterOrEqual.h"
#include "Comparative/Lesser.h"
#include "Comparative/LesserOrEqual.h"
#include "Comparative/Like.h"
#include "Comparative/NotLike.h"
#include "Comparative/IsNull.h"
#include "Comparative/IsNotNull.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            struct ComparativeFactory {
                static SPtrCriteria CreateAND(const SPtrCriteria &lhs, const SPtrCriteria &rhs);
                static SPtrCriteria CreateOR(const SPtrCriteria &lhs, const SPtrCriteria &rhs);
                static SPtrCriteria CreateEQ(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateNEQ(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateGT(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateGTE(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateLT(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateLTE(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateLike(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateNotLike(const SPtrColumn &column, const Data::SPtrValue &value);
                static SPtrCriteria CreateIsNull(const SPtrColumn &column);
                static SPtrCriteria CreateIsNotNull(const SPtrColumn &column);
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_H
