//
// Created by GoPlan on 14/05/2015.
//

#include "Identity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            Identity::Identity() {

            }

            Identity::~Identity() {
            }

            void Identity::Add(Field const &field) {
                auto column_name = field.getColumn().getName();
                auto field_pair = make_pair(column_name, field);

                this->fieldsMap.insert(field_pair);
            }

            void Identity::AddMultipleFields(initializer_list<Field*> fields) {
                for(const Field* field : fields){
                    this->Add(*field);
                }
            }
        }
    }
}
