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
                auto column = fieldPtr->column();
                auto column_name = column.name();
                auto field_pair = make_pair(column_name, fieldPtr);
                this->_fieldsMap.insert(field_pair);
            }

            void Identity::AddMultipleFieldsPtr(std::initializer_list<Field *> fields) {
                for (Field *fieldPtr : fields) {
                    this->AddFieldPtr(fieldPtr);
                }
            }

            const std::unordered_map<std::string, Field *> &Identity::FieldsMap() {
                return _fieldsMap;
            }

            const Field *Identity::GetFieldPtr(std::string columnName) {
                auto fieldPtr = _fieldsMap[columnName];
                return fieldPtr;
            }
        }
    }
}
