//
// Created by LE, Duc Anh on 6/15/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H

#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Contract {
                class IPredicateFormatter;
            }

            namespace Helper {
                class PredicateHelper {
                public:
                    PredicateHelper() = delete;
                    virtual ~PredicateHelper() = delete;
                    PredicateHelper(const PredicateHelper &rhs) = delete;
                    PredicateHelper &operator=(const PredicateHelper &rhs) = delete;

                    static std::string ToStringCopy(const SPtrPredicate &predicate,
                                                    const Contract::IPredicateFormatter &formatter);
                };
            }


        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
