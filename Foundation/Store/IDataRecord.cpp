//
// Created by LE, Duc Anh on 6/16/15.
//

#include <Foundation/Exception/cldeEntityException.h>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
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

const std::string Cloude::Foundation::Store::IDataRecord::CopyToString() const {

    std::string result;

    auto sptrFieldVector = getFields();

    std::for_each(sptrFieldVector.crbegin(), sptrFieldVector.crend(),
                  [&result](const SPtrField &field) {
                      if (result.length() != 0) {
                          result += " | ";
                      }

                      if (field->isNull()) {
                          result += "null";
                      } else {
                          result += field->getValue()->CopyToString();
                      }
                  });

    return result;
}

Cloude::Foundation::SPtrFieldVector Cloude::Foundation::Store::IDataRecord::getFields() const {

    SPtrFieldVector fieldVector;

    for (auto pairField : _fieldMap) {
        fieldVector.push_back(pairField.second);
    }

    return fieldVector;
}

Cloude::Foundation::SPtrColumnVector Cloude::Foundation::Store::IDataRecord::getColumns() const {

    SPtrColumnVector columnVector;

    for (auto pairField : _fieldMap) {
        columnVector.push_back(pairField.second->getColumn());
    }

    return columnVector;
}

const std::string &Cloude::Foundation::Store::IDataRecord::ToString() const {
    std::string msg{"ToString is not supported, use CopyToString intead"};
    throw Exception::cldeNonSupportedFunctionException{msg};
}

const char *Cloude::Foundation::Store::IDataRecord::ToCString() const {
    std::string msg{"ToCString is not supported, use CopyToString intead"};
    throw Exception::cldeNonSupportedFunctionException{msg};
}
