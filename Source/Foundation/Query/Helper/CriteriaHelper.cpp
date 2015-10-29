//
// Created by LE, Duc Anh on 6/15/15.
//

#include "CriteriaHelper.h"
#include "../Contract/IPredicateFormatter.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Helper {

                std::string CriteriaHelper::CopyToString(const SPtrCriteria &sptrCriteria,
                                                         const Contract::IPredicateFormatter &formatter) {
                    return formatter.ParsePredicateToStringCopy(sptrCriteria);
                }

                std::string CriteriaHelper::CopyToString(const SPtrCriteria &sptrCriteria,
                                                         const CriteriaHelper::FPtrProcessor fptrProcessor) {
                    return fptrProcessor(sptrCriteria);
                }
            }
        }
    }
}
