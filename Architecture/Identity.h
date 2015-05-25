//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <unordered_map>
#include "Entity.h"

namespace Cloude {
    namespace Architecture {

        class Field;

        class EntityStore;

        class Identity : public std::enable_shared_from_this<Identity> {
        public:
            Identity() = default;
            Identity(const Identity &srcIdentity) = default;
            Identity &operator=(const Identity &srcIdentity) = default;
            virtual ~Identity() = default;

            explicit Identity(std::shared_ptr<Field> field);
            explicit Identity(Field *ptrField);

            std::shared_ptr<Identity> SetField(std::shared_ptr<Field> field);
            std::shared_ptr<Identity> SetField(Field *ptrField);
            std::shared_ptr<Identity> SetField(const std::initializer_list<Field *> &ptrFieldList);

            std::shared_ptr<Entity> &getEntity() {
                return _entity;
            }

        protected:
            std::shared_ptr<Entity> _entity;
        };
    }
}

#endif //CLOUD_E_CPLUS_IDENTITY_H
