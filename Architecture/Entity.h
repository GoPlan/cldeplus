//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITY_H
#define CLOUD_E_CPLUS_ENTITY_H

#include "unordered_map"
#include "Field.h"
#include "Identity.h"

namespace Cloude {
    namespace Architecture {

        class Entity {
        public:
            explicit Entity(const std::shared_ptr<Identity> &identity);
            ~Entity() = default;
            Entity(const Entity &srcEntity) = delete;
            Entity &operator=(Entity &srcEntity) = delete;

            std::shared_ptr<Field> operator[](const std::string &columnName);
            std::shared_ptr<Field> getField(const std::string &columnName);

            void setField(std::shared_ptr<Field> &field);
            void setField(Field *ptrField);
            void setMultiFields(std::initializer_list<std::shared_ptr<Field>> &fieldsList);
            void setMultiFields(std::initializer_list<Field *> ptrFieldsList);

            bool HasField(const std::string &fieldName);
            unsigned long Size();

            std::shared_ptr<Identity> &getIdentity() {
                return _identity;
            }

        private:
            std::shared_ptr<Identity> _identity;
            std::unordered_map<std::string, std::shared_ptr<Field>> _fieldsMap;
        };
    }
}


#endif //CLOUD_E_CPLUS_ENTITY_H
