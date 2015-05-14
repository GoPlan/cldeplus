//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <unordered_map>
#include <vector>
#include <string>
#include "Field.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Identity {

            public:
                
                Identity();

                virtual ~Identity();

                const unordered_map<string, const Field &> &getFieldsMap() const {
                    return fieldsMap;
                }

                void Add(Field const &field);

                void AddMultipleFields(initializer_list<Field *> fields);


            private:
                unordered_map<string, const Field &> fieldsMap;
            };

        }
    }
}


#endif //CLOUD_E_CPLUS_IDENTITY_H
