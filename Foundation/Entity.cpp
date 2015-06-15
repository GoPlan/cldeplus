//
// Created by GoPlan on 14/05/2015.
//

#include <memory>
#include "Entity.h"
#include "Identity.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

        Entity::Entity(const std::shared_ptr<Identity> &identity) : _identity(identity) {
            for (auto fieldPair : _identity->getFieldsMap()) {
                auto field = fieldPair.second;
                setField(field);
            }
        }

        const shared_ptr<Field> &Entity::operator[](const string &columnName) const {
            return getField(columnName);
        }

        const shared_ptr<Field> &Entity::getField(const string &columnName) const {

            auto search = _fieldsMap.find(columnName);

            if (search == _fieldsMap.end()) {
                throw Exception::cldeEntityException(columnName + " field is not found");
            }

            return search->second;
        }

        const std::shared_ptr<Field> &Entity::operator[](const char *columnName) const {
            return getField(columnName);
        }

        const shared_ptr<Field> &Entity::getField(const char *columnName) const {
            std::string columnNameStr(columnName);
            return getField(columnNameStr);
        }

        void Entity::setField(shared_ptr<Field> &field) {
            shared_ptr<Field> spField(field);
            _fieldsMap[field->getColumn()->getName()] = spField;
        }

        void Entity::setField(Field *ptrField) {
            shared_ptr<Field> spField(ptrField);
            _fieldsMap[ptrField->getColumn()->getName()] = spField;
        }

        void Entity::setMultiFields(std::initializer_list<std::shared_ptr<Field>> &fieldsList) {
            for (auto field : fieldsList) {
                setField(const_cast<std::shared_ptr<Field> &>(field));
            }
        }

        void Entity::setMultiFields(std::initializer_list<Field *> ptrFieldsList) {
            for (auto ptrField : ptrFieldsList) {
                setField(ptrField);
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