//
// Created by GoPlan on 14/05/2015.
//

#include <memory>
#include <stdexcept>
#include "Entity.h"

using namespace std;

namespace Cloude {
    namespace Foundation {

        Entity::Entity(const SPtrIdentity &identity) : _identity(identity) {

            if (!identity) {
                std::string msg{"Identity can not be nullptr or undefined"};
                throw std::invalid_argument{msg};
            }

            for (auto fieldPair : _identity->getFieldsMap()) {
                auto field = fieldPair.second;
                setField(field);
            }
        }

        const SPtrField &Entity::operator[](const string &columnName) const {
            return getField(columnName);
        }

        const SPtrField &Entity::getField(const string &columnName) const {

            auto search = _fieldsMap.find(columnName);

            if (search == _fieldsMap.end()) {
                throw Exception::cldeEntityException(columnName + " field is not found");
            }

            return search->second;
        }

        const SPtrField &Entity::operator[](const char *columnName) const {
            return getField(columnName);
        }

        const SPtrField &Entity::getField(const char *columnName) const {
            std::string columnNameStr(columnName);
            return getField(columnNameStr);
        }

        void Entity::setField(SPtrField &field) {
            SPtrField spField(field);
            _fieldsMap[field->getColumn()->getName()] = spField;
        }

        void Entity::setField(Field *ptrField) {
            shared_ptr<Field> spField(ptrField);
            _fieldsMap[ptrField->getColumn()->getName()] = spField;
        }

        void Entity::setMultiFields(std::initializer_list<SPtrField> &fieldsList) {
            for (auto field : fieldsList) {
                setField(const_cast<SPtrField &>(field));
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