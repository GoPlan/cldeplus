//
// Created by LE, Duc Anh on 6/15/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H

#include <string>
#include <functional>
#include "../Criteria.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Contract {
                class IPredicateFormatter;
            }

            namespace Helper {

                class CriteriaHelper {
                    CriteriaHelper() = delete;
                    CriteriaHelper(const CriteriaHelper &) = delete;
                    CriteriaHelper(CriteriaHelper &&) = delete;
                    CriteriaHelper &operator=(const CriteriaHelper &) = delete;
                    CriteriaHelper &operator=(CriteriaHelper &&) = delete;
                    virtual ~CriteriaHelper() = delete;

                public:
                    using FPtrProcessor = std::function<std::string(const SPtrCriteria &)>;

                    static std::string CopyToString(const SPtrCriteria &sptrCriteria, const Contract::IPredicateFormatter &formatter);
                    static std::string CopyToString(const SPtrCriteria &sptrCriteria, const FPtrProcessor fptrProcessor);
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_PREDICATEHELPER_H
