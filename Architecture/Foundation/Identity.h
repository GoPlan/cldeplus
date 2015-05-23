//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <string>
#include <unordered_map>
#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Field;

            class EntityStore;

            class Identity : public enable_shared_from_this<Identity> {
            public:
                Identity();
                virtual ~Identity();
                shared_ptr<Identity> SetField(shared_ptr<Field> spField);

                const shared_ptr<Entity> &getSpEntity() const {
                    return _spEntity;
                }

            protected:
                shared_ptr<Entity> _spEntity;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_IDENTITY_H
