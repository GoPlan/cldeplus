//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <unordered_map>
#include "Field.h"

namespace Cloude {
    namespace Architecture {

        using FieldsMap = std::unordered_map<std::string, std::shared_ptr<Field>>;

        class Identity {
        public:
            Identity() = default;
            Identity(const Identity &srcIdentity) = default;
            Identity &operator=(const Identity &srcIdentity) = default;
            virtual ~Identity() = default;

            explicit Identity(const std::initializer_list<Field *> ptrFieldList);
            explicit Identity(const std::initializer_list<std::shared_ptr<Field>> &fieldsList);

            void SetField(std::shared_ptr<Field> &field);
            void SetField(Field *ptrField);
            void SetMultiFields(const std::initializer_list<Field *> &ptrFieldList);
            void SetMultiFields(const std::initializer_list<std::shared_ptr<Field>> &spFieldList);

            const FieldsMap &getFieldsMap() {
                return _fieldsMap;
            };

        protected:
            FieldsMap _fieldsMap;
        };
    }
}

#endif //CLOUD_E_CPLUS_IDENTITY_H
