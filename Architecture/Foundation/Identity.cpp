//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Identity::Identity() {

            }

            Identity::Identity(initializer_list<Field *> fields) {
                AddMultipleFields(fields);
            }

            Identity::~Identity() {
            }

            void Identity::Add(Field &field) {
                auto column = field.column();
                auto column_name = column.name();
                auto field_pair = make_pair(column_name, &field);

                this->_fields_map.insert(field_pair);
            }

            void Identity::AddMultipleFields(initializer_list<Field *> fields) {
                for (Field *field : fields) {
                    this->Add(*field);
                }
            }

            const unordered_map<string, const Field *> &Identity::FieldsMap() {
                return _fields_map;
            }

            const Field &Identity::GetField(string columnName) {
                auto field_ptr = (_fields_map[columnName]);
                return *field_ptr;
            }
        }
    }
}
