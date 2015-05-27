//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITY_H
#define CLOUD_E_CPLUS_ENTITY_H

#include "unordered_map"

#include "Field.h"

namespace Cloude {
    namespace Architecture {

        class Identity;

        class Entity {
        public:
            Entity(const Entity &srcEntity) = delete;
            Entity &operator=(Entity &srcEntity) = delete;
            virtual ~Entity() = default;

            explicit Entity(const std::shared_ptr<Identity> &identity) : _identity(identity) { };

            std::shared_ptr<Field> operator[](const std::string &columnName) const;
            std::shared_ptr<Field> GetField(const std::string &columnName) const;
            void InsertField(std::shared_ptr<Field> field);
            void InsertField(Field *ptrField);

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
