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

            Identity::Identity(initializer_list<Field *> fields) {
                AddMultipleFieldsPtr(fields);
            }

            Identity::~Identity() {
            }

            void Identity::AddFieldPtr(Field *fieldPtr) {
                auto column = fieldPtr->column();
                auto column_name = column.name();
                auto field_pair = make_pair(column_name, fieldPtr);
                this->_fields_map.insert(field_pair);
            }

            void Identity::AddMultipleFieldsPtr(initializer_list<Field *> fields) {
                for (Field *fieldPtr : fields) {
                    this->AddFieldPtr(fieldPtr);
                }
            }

            const unordered_map<string, const Field *> &Identity::FieldsMap() {
                return _fields_map;
            }

            const Field *Identity::GetFieldPtr(string columnName) {
                return _fields_map[columnName];
            }
        }
    }
}
