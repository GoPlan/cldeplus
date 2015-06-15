//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_ENTITY_H

#include "unordered_map"
#include "Field.h"
#include "Identity.h"
#include "Exception/cldeEntityException.h"

namespace Cloude {
    namespace Foundation {

        class Entity {

        public:
            explicit Entity(const SPtrIdentity &identity);
            ~Entity() = default;
            Entity(const Entity &srcEntity) = delete;
            Entity &operator=(Entity &srcEntity) = delete;

            const SPtrField &operator[](const std::string &columnName) const;
            const SPtrField &operator[](const char *columnName) const;
            const SPtrField &getField(const std::string &columnName) const;
            const SPtrField &getField(const char *columnName) const;

            void setField(SPtrField &field);
            void setField(Field *ptrField);
            void setMultiFields(std::initializer_list<SPtrField> &fieldsList);
            void setMultiFields(std::initializer_list<Field *> ptrFieldsList);

            bool HasField(const std::string &fieldName);
            unsigned long Size();

            const SPtrIdentity &getIdentity() { return _identity; }

        protected:
            SPtrIdentity _identity;
            SptrFieldMap _fieldsMap;
        };

        using SPtrEntity = std::shared_ptr<Entity>;
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_ENTITY_H
