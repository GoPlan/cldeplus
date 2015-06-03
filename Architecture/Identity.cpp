//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        void Identity::SetField(std::shared_ptr<Field> &field) {
            _fieldsMap[field->getColumn()->getName()] = field;
        }

        void Identity::SetField(Field *ptrField) {
            shared_ptr<Field> spField(ptrField);
            _fieldsMap[ptrField->getColumn()->getName()] = spField;
        }

        void Identity::SetMultiFields(const std::initializer_list<Field *> &ptrFieldList) {
            for (auto ptrField : ptrFieldList) {
                SetField(ptrField);
            }
        }

        void Identity::SetMultiFields(const std::initializer_list<std::shared_ptr<Field>> &spFieldList) {
            for (auto spField : spFieldList) {
                SetField(const_cast<std::shared_ptr<Field> &>(spField));
            }
        }

        Identity::Identity(const std::initializer_list<Field *> ptrFieldList) {
            SetMultiFields(ptrFieldList);
        }

        Identity::Identity(const std::initializer_list<std::shared_ptr<Field>>& fieldsList) {
            SetMultiFields(fieldsList);
        }
    }
}
