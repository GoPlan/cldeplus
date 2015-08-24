//
// Created by LE, Duc Anh on 6/11/15.
//

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

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class ComparativeFactory {

            public:
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
