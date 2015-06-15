//
// Created by LE, Duc Anh on 6/15/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H

#include <string>
#include <functional>

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Contract {
                class IPredicateFormatter;
            }

            class Predicate;

            namespace Helper {

                class PredicateHelper {

                public:
                    using SPtrPredicate = std::shared_ptr<Query::Predicate>;
                    using FPtrProcessor = std::function<std::string(const SPtrPredicate &)>;

                public:
                    PredicateHelper() = delete;
                    virtual ~PredicateHelper() = delete;
                    PredicateHelper(const PredicateHelper &rhs) = delete;
                    PredicateHelper &operator=(const PredicateHelper &rhs) = delete;

                    static std::string ToStringCopy(const SPtrPredicate &predicate,
                                                    const Contract::IPredicateFormatter &formatter);

                    static std::string ToStringCopy(const SPtrPredicate &predicate,
                                                    const FPtrProcessor fptrProcessor);

                };
            }


        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
