//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_CONTRACT_IPREDICATEFORMATTER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_CONTRACT_IPREDICATEFORMATTER_H

#include <string>
#include "../Criteria.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Contract {

                class IPredicateFormatter {

                public:
                    virtual std::string ParsePredicateToStringCopy(const SPtrCriteria &criteria) const = 0;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_CONTRACT_IPREDICATEFORMATTER_H
