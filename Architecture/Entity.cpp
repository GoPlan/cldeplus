//
// Created by GoPlan on 14/05/2015.
//

#include <memory>
#include <Architecture/Exception/EntityException.h>
#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        shared_ptr<Field> Entity::operator[](const string &columnName) {
            return GetField(columnName);
        }

        shared_ptr<Field> Entity::GetField(const string &columnName) {

            auto search = _fieldsMap.find(columnName);

            if (search == _fieldsMap.end()) {
                throw Exception::EntityException(columnName + " field is not found");
            }

            return search->second;
        }

        void Entity::InsertField(shared_ptr<Field> &field) {
            _fieldsMap.insert(make_pair(field->getColumn()->getName(), field));
        }

        void Entity::InsertField(Field *ptrField) {
            _fieldsMap.insert(make_pair(ptrField->getColumn()->getName(), shared_ptr<Field>(ptrField)));
        }
    }
}