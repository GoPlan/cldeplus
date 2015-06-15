//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"
#include "Field.h"

namespace Cloude {
    namespace Foundation {

        void Identity::setField(SPtrField &field) {
            _fieldsMap[field->getColumn()->getName()] = field;
        }

        void Identity::setField(Field *ptrField) {
            SPtrField spField(ptrField);
            _fieldsMap[ptrField->getColumn()->getName()] = spField;
        }

        void Identity::setMultiFields(const std::initializer_list<Field *> &ptrFieldList) {
            for (auto ptrField : ptrFieldList) {
                setField(ptrField);
            }
        }

        void Identity::setMultiFields(const std::initializer_list<SPtrField> &spFieldList) {
            for (auto spField : spFieldList) {
                setField(const_cast<std::shared_ptr<Field> &>(spField));
            }
        }

        Identity::Identity(const std::initializer_list<Field *> ptrFieldList) {
            setMultiFields(ptrFieldList);
        }

        Identity::Identity(const std::initializer_list<SPtrField> &fieldsList) {
            setMultiFields(fieldsList);
        }
    }
}
