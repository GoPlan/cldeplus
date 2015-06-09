//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <unordered_map>
#include "Field.h"

namespace Cloude {
    namespace Foundation {
        class Identity {
            using FieldsMap = std::unordered_map<std::string, std::shared_ptr<Field>>;

        public:
            Identity() = default;
            Identity(const Identity &srcIdentity) = default;
            Identity &operator=(const Identity &srcIdentity) = default;
            virtual ~Identity() = default;

            explicit Identity(const std::initializer_list<Field *> ptrFieldList);
            explicit Identity(const std::initializer_list<std::shared_ptr<Field>> &fieldsList);

            void setField(std::shared_ptr<Field> &field);
            void setField(Field *ptrField);
            void setMultiFields(const std::initializer_list<Field *> &ptrFieldList);
            void setMultiFields(const std::initializer_list<std::shared_ptr<Field>> &spFieldList);

            const FieldsMap &getFieldsMap() {
                return _fieldsMap;
            };

        protected:
            FieldsMap _fieldsMap;
        };
    }
}

#endif //CLOUD_E_CPLUS_IDENTITY_H
