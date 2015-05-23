//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITY_H
#define CLOUD_E_CPLUS_ENTITY_H

#include <unordered_map>
#include "Field.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class Identity;

            class Entity {
            public:
                Entity(const shared_ptr<Identity>& identity) : _identity(identity) { };

                virtual ~Entity() { };

                shared_ptr<Field> operator[](const string &columnName);
                shared_ptr<Field> GetField(const string &columnName);
                void InsertField(shared_ptr<Field> field);

                weak_ptr<Identity> getIdentity() const {
                    return _identity;
                }

            private:
                weak_ptr<Identity> _identity;
                unordered_map<string, shared_ptr<Field>> _fieldsMap;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITY_H
