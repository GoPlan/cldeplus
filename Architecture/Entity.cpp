//
// Created by GoPlan on 14/05/2015.
//

#include <memory>
#include <Architecture/Exception/EntityException.h>
#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Architecture {

        Entity::Entity(const std::shared_ptr<Identity> &identity) : _identity(identity) {
            for (auto fieldPair : _identity->getFieldsMap()) {
                auto field = fieldPair.second;
                SetField(field);
            }
        }

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

        void Entity::SetField(shared_ptr<Field> &field) {

            if (HasField(field->getColumn()->getName())) {
                return;
            }

            shared_ptr<Field> spField(field);

            _fieldsMap.insert(make_pair(field->getColumn()->getName(), spField));
        }

        void Entity::SetField(Field *ptrField) {

            if (HasField(ptrField->getColumn()->getName())) {
                return;
            }

            shared_ptr<Field> spField(ptrField);

            _fieldsMap.insert(make_pair(ptrField->getColumn()->getName(), spField));
        }

        void Entity::SetMultiFields(std::initializer_list<std::shared_ptr<Field>> &fieldsList) {
            for (auto field : fieldsList) {
                SetField(const_cast<std::shared_ptr<Field> &>(field));
            }
        }

        void Entity::SetMultiFields(std::initializer_list<Field *> ptrFieldsList) {
            for (auto ptrField : ptrFieldsList) {
                SetField(ptrField);
            }
        }

        bool Entity::HasField(const std::string &fieldName) {
            auto search = _fieldsMap.find(fieldName);
            auto result = !(search == _fieldsMap.end());
            return result;
        }

        unsigned long Entity::Size() {
            return _fieldsMap.size();
        }
    }
}