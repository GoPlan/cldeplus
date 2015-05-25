//
// Created by GoPlan on 14/05/2015.
//

#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        shared_ptr<Field> Entity::operator[](const string &columnName) const {
            return GetField(columnName);
        }

        shared_ptr<Field> Entity::GetField(const string &columnName) const {

            auto search = _fieldsMap.find(columnName);

            if (search == _fieldsMap.end()) {
                // TODO: Throws field not found exception
                shared_ptr<Field> spField;
                return spField;
            }

            return search->second;
        }

        void Entity::InsertField(shared_ptr<Field> field) {
            _fieldsMap.insert(make_pair(field->getColumn()->getName(), field));
        }

        void Entity::InsertField(Field *ptrField) {
            _fieldsMap.insert(make_pair(ptrField->getColumn()->getName(), shared_ptr<Field>(ptrField)));
        }
    }
}