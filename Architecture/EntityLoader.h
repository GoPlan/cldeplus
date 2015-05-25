//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYLOADER_H
#define CLOUD_E_CPLUS_ENTITYLOADER_H

#include "Identity.h"
#include "Entity.h"

namespace Cloude {
    namespace Architecture {

        class EntityLoader {
        public:
            virtual ~EntityLoader() = default;
            virtual std::unique_ptr<Identity> NextPrimaryKey() = 0;
            virtual void LoadEntity(std::shared_ptr<Identity> &identity) = 0;
        };
    }
}


#endif //CLOUD_E_CPLUS_ENTITYLOADER_H
