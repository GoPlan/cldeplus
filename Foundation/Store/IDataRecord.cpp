//
// Created by LE, Duc Anh on 6/16/15.
//

#include <Foundation/Exception/cldeEntityException.h>
#include "IDataRecord.h"

void Cloude::Foundation::Store::IDataRecord::setField(const SPtrField &field) {
    _fieldMap[field->getColumn()->getName()] = field;
}
void Cloude::Foundation::Store::IDataRecord::setField(Field *ptrField) {
    SPtrField spField(ptrField);
    _fieldMap[ptrField->getColumn()->getName()] = spField;
}
void Cloude::Foundation::Store::IDataRecord::setMultiFields(const SPtrFieldVector &fieldVector) {
    for (auto &sptrField : fieldVector) {
        setField(sptrField);
    }
}
void Cloude::Foundation::Store::IDataRecord::setMultiFields(const std::vector<Field *> &fieldVector) {
    for (auto ptrField : fieldVector) {
        setField(ptrField);
    }
}
const Cloude::Foundation::SPtrField &Cloude::Foundation::Store::IDataRecord::operator[](
        const std::string &columnName) const {
    return getField(columnName);
}
const Cloude::Foundation::SPtrField &Cloude::Foundation::Store::IDataRecord::operator[](
        const char *columnName) const {
    return getField(columnName);
}
const Cloude::Foundation::SPtrField &Cloude::Foundation::Store::IDataRecord::getField(
        const std::string &columnName) const {

    auto search = _fieldMap.find(columnName);

    if (search == _fieldMap.end()) {
        throw Exception::cldeEntityException(columnName + " field is not found");
    }

    return search->second;
}
const Cloude::Foundation::SPtrField &Cloude::Foundation::Store::IDataRecord::getField(const char *columnName) const {
    std::string columnNameStr(columnName);
    return getField(columnNameStr);
}
bool Cloude::Foundation::Store::IDataRecord::HasField(const std::string &fieldName) {
    auto search = _fieldMap.find(fieldName);
    auto result = !(search == _fieldMap.end());
    return result;
}
unsigned long Cloude::Foundation::Store::IDataRecord::Size() {
    return _fieldMap.size();
}
