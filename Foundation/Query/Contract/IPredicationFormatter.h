//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_IPREDICATIONFORMATTER_H
#define CLOUD_E_CPLUS_IPREDICATIONFORMATTER_H

#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class Predicate;

            namespace Contract {
                class IPredicationFormatter {
                public:
                    virtual const std::string CopyFormat(const Query::Predicate &predicate) const = 0;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_IPREDICATIONFORMATTER_H
