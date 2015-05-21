//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Identity::Identity() {

            }

            Identity::Identity(Field *fieldPtr) {
                this->AddFieldPtr(fieldPtr);
            }

            Identity::Identity(std::initializer_list<Field *> fields) {
                AddMultipleFieldsPtr(fields);
            }

            Identity::~Identity() {
            }

            void Identity::AddFieldPtr(Field *fieldPtr) {
                auto column = fieldPtr->getColumn();
                auto columnName = column.getName();
                auto fieldPair = make_pair(columnName, fieldPtr);
                this->_fieldsMap.insert(fieldPair);
            }

            void Identity::AddMultipleFieldsPtr(std::initializer_list<Field *> fields) {
                for (Field *fieldPtr : fields) {
                    this->AddFieldPtr(fieldPtr);
                }
            }

            const Field *Identity::GetFieldPtr(std::string columnName) {
                auto fieldPtr = _fieldsMap[columnName];
                return fieldPtr;
            }
        }
    }
}
