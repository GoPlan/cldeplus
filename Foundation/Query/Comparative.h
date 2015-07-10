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
            SPtrCriteria CreateAND(const SPtrCriteria &lhs, const SPtrCriteria &rhs);
            SPtrCriteria CreateOR(const SPtrCriteria &lhs, const SPtrCriteria &rhs);
            SPtrCriteria CreateEQ(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateNEQ(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateGT(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateGTE(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateLT(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateLTE(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateLike(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateNotLike(const SPtrColumn &column, const Data::SPtrValue &value);
            SPtrCriteria CreateIsNull(const SPtrColumn& column);
            SPtrCriteria CreateIsNotNull(const SPtrColumn& column);
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_COMPARATIVE_H
