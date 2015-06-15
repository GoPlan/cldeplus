//
// Created by LE, Duc Anh on 6/15/15.
//

#include <Foundation/Query/Contract/IPredicateFormatter.h>
#include "PredicateHelper.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Helper {

                std::string PredicateHelper::ToStringCopy(const SPtrPredicate &predicate,
                                                          const Contract::IPredicateFormatter &formatter) {
                    return formatter.ParsePredicateToStringCopy(predicate);
                }

                std::string PredicateHelper::ToStringCopy(const SPtrPredicate &predicate,
                                                          const PredicateHelper::FPtrProcessor fptrProcessor) {
                    return fptrProcessor(predicate);
                }

            }
        }
    }
}
