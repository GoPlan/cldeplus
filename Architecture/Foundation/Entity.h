//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITY_H
#define CLOUD_E_CPLUS_ENTITY_H

#include "Column.h"
#include "Identity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {
            class Entity {

            public:
                Entity(Identity &ident) : _identity(ident) { };
                virtual ~Entity() { };

                Identity &getIdentity() const {
                    return _identity;
                }

            private:
                Identity &_identity;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITY_H
