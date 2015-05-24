//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITY_H
#define CLOUD_E_CPLUS_ENTITY_H

#include <unordered_map>
#include "Field.h"

namespace Cloude {
    namespace Architecture {
        class Identity;

        class Entity {
        public:
            Entity(const std::shared_ptr<Identity> &identity) : _identity(identity) { };
            Entity(const Entity &srcEntity);
            Entity &operator=(Entity &srcEntity);
            virtual ~Entity();

            std::shared_ptr<Field> operator[](const std::string &columnName);
            std::shared_ptr<Field> GetField(const std::string &columnName);
            void InsertField(std::shared_ptr<Field> field);

            std::weak_ptr<Identity> getIdentity() const {
                return _identity;
            }

        private:
            std::weak_ptr<Identity> _identity;
            std::unordered_map<std::string, std::shared_ptr<Field>> _fieldsMap;
        };
    }
}


#endif //CLOUD_E_CPLUS_ENTITY_H
