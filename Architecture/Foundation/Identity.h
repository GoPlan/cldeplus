//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <unordered_map>
#include "Field.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Identity {

            public:
                Identity();
                Identity(initializer_list<Field *> fields);
                virtual ~Identity();

                const unordered_map<string, const Field *> &FieldsMap() const {
                    return fieldsMap;
                }

                void Add(Field &field);
                void AddMultipleFields(initializer_list<Field *> fields);

            protected:
                unordered_map<string, const Field *> fieldsMap;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_IDENTITY_H
