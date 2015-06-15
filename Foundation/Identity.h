//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
#define CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H

#include <unordered_map>
#include "Field.h"

namespace Cloude {
    namespace Foundation {

        class Identity {

        public:
            Identity() = default;
            Identity(const Identity &srcIdentity) = default;
            Identity &operator=(const Identity &srcIdentity) = default;
            virtual ~Identity() = default;

            explicit Identity(const std::initializer_list<Field *> ptrFieldList);
            explicit Identity(const std::initializer_list<std::shared_ptr<Field>> &fieldsList);

            void setField(SPtrField &field);
            void setField(Field *ptrField);
            void setMultiFields(const std::initializer_list<Field *> &ptrFieldList);
            void setMultiFields(const std::initializer_list<std::shared_ptr<Field>> &spFieldList);

            const SptrFieldMap &getFieldsMap() { return _fieldsMap; };

        protected:
            SptrFieldMap _fieldsMap;
        };

        using SPtrIdentity = std::shared_ptr<Identity>;
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_IDENTITY_H
