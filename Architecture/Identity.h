//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <string>
#include <unordered_map>
#include "Entity.h"

namespace Cloude {
    namespace Architecture {

        class Field;

        class EntityStore;

        class Identity : public std::enable_shared_from_this<Identity> {
        public:
            Identity();
            Identity(const Identity &srcIdentity);
            Identity &operator=(const Identity &srcIdentity);
            virtual ~Identity();

            std::shared_ptr<Identity> SetField(std::shared_ptr<Field> spField);

            const std::shared_ptr<Entity> &getSpEntity() const {
                return _spEntity;
            }

        protected:
            std::shared_ptr<Entity> _spEntity;
        };
    }
}

#endif //CLOUD_E_CPLUS_IDENTITY_H
