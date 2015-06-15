//
// Created by LE, Duc Anh on 6/13/15.
//

#ifndef CLOUD_E_CPLUS_PREDICATESENTINEL_H
#define CLOUD_E_CPLUS_PREDICATESENTINEL_H

#include "Predicate.h"

namespace Cloude {
    namespace Foundation {
        namespace Query {

            class PredicateSentinel : public Predicate {

            public:
                PredicateSentinel() = default;
                virtual ~PredicateSentinel() = default;
                PredicateSentinel(const PredicateSentinel &rhs) = default;
                PredicateSentinel &operator=(const PredicateSentinel &rhs) = default;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_PREDICATESENTINEL_H
