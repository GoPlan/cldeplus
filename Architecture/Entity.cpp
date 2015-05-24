//
// Created by GoPlan on 14/05/2015.
//

#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        Entity::Entity(const Entity &srcEntity) {

        }

        Entity &Entity::operator=(Entity &srcEntity) {
            return *this;
        }

        Entity::~Entity() {

        }

        shared_ptr<Field> Entity::operator[](const string &columnName) {
            return GetField(columnName);
        }

        shared_ptr<Field> Entity::GetField(const string &columnName) {

            auto search = _fieldsMap.find(columnName);

            if (search == _fieldsMap.end()) {
                //TODO: Throws field not found exception
                shared_ptr<Field> spField;
                return spField;
            }

            return search->second;
        }

        void Entity::InsertField(shared_ptr<Field> field) {
            _fieldsMap.insert(make_pair(field->getSpColumn()->getName(), field));
        }


    }
}