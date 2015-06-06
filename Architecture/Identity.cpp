//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        void Identity::setField(std::shared_ptr<Field> &field) {
            _fieldsMap[field->getColumn()->getName()] = field;
        }

        void Identity::setField(Field *ptrField) {
            shared_ptr<Field> spField(ptrField);
            _fieldsMap[ptrField->getColumn()->getName()] = spField;
        }

        void Identity::setMultiFields(const std::initializer_list<Field *> &ptrFieldList) {
            for (auto ptrField : ptrFieldList) {
                setField(ptrField);
            }
        }

        void Identity::setMultiFields(const std::initializer_list<std::shared_ptr<Field>> &spFieldList) {
            for (auto spField : spFieldList) {
                setField(const_cast<std::shared_ptr<Field> &>(spField));
            }
        }

        Identity::Identity(const std::initializer_list<Field *> ptrFieldList) {
            setMultiFields(ptrFieldList);
        }

        Identity::Identity(const std::initializer_list<std::shared_ptr<Field>>& fieldsList) {
            setMultiFields(fieldsList);
        }
    }
}
