//
// Created by LE, Duc Anh on 6/15/15.
//

#include <Foundation/Query/Contract/IPredicateFormatter.h>
#include "CriteriaHelper.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Helper {

                std::string CriteriaHelper::ToStringCopy(const SPtrCriteria &sptrCriteria,
                                                         const Contract::IPredicateFormatter &formatter) {
                    return formatter.ParsePredicateToStringCopy(sptrCriteria);
                }

                std::string CriteriaHelper::ToStringCopy(const SPtrCriteria &sptrCriteria,
                                                         const CriteriaHelper::FPtrProcessor fptrProcessor) {
                    return fptrProcessor(sptrCriteria);
                }
            }
        }
    }
}
