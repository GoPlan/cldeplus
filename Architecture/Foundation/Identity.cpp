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
                auto column = field.getColumn();
                auto column_name = column.getName();
                auto field_pair = make_pair(column_name, &field);

                this->fieldsMap.insert(field_pair);
            }

            void Identity::AddMultipleFields(initializer_list<Field *> fields) {
                for (Field *field : fields) {
                    this->Add(*field);
                }
            }
        }
    }
}
