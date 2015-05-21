//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_IDENTITY_H
#define CLOUD_E_CPLUS_IDENTITY_H

#include <unordered_map>
#include "Field.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Identity {

            public:
                Identity();
                Identity(Field *fieldPtr);
                Identity(std::initializer_list<Field *> fields);
                virtual ~Identity();

                const Field *GetFieldPtr(std::string columnName);
                const std::unordered_map<std::string, Field *> &getFieldsMap() {
                    return _fieldsMap;
                }

                void AddFieldPtr(Field *fieldPtr);
                void AddMultipleFieldsPtr(std::initializer_list<Field *> fields);

            protected:
                std::unordered_map<std::string, Field *> _fieldsMap;

            };

        }
    }
}


#endif //CLOUD_E_CPLUS_IDENTITY_H
