//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITYLOADER_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITYLOADER_H

#include "Identity.h"

namespace Cloude {
    namespace Foundation {

        class EntityLoader {

        public:
            virtual ~EntityLoader() = default;
            virtual SPtrIdentity NextPrimaryKey() const = 0;
        };
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITYLOADER_H
