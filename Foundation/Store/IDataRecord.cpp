//
// Created by LE, Duc Anh on 6/16/15.
//

#include <Foundation/Exception/cldeEntityException.h>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "IDataRecord.h"

void Cloude::Foundation::Store::IDataRecord::setField(const SPtrCell &cell) {
    _cellMap[cell->getColumn()->getName()] = cell;
}

void Cloude::Foundation::Store::IDataRecord::setField(Cell *ptrCell) {
    SPtrCell sptrCell(ptrCell);
    _cellMap[ptrCell->getColumn()->getName()] = sptrCell;
}

void Cloude::Foundation::Store::IDataRecord::setMultiFields(const SPtrCellVector &cellVector) {
    for (auto &sptrField : cellVector) {
        setField(sptrField);
    }
}

void Cloude::Foundation::Store::IDataRecord::setMultiFields(const std::vector<Cell *> &cellVector) {
    for (auto ptrField : cellVector) {
        setField(ptrField);
    }
}

const Cloude::Foundation::SPtrCell &Cloude::Foundation::Store::IDataRecord::operator[](
        const std::string &columnName) const {
    return getField(columnName);
}

const Cloude::Foundation::SPtrCell &Cloude::Foundation::Store::IDataRecord::operator[](
        const char *columnName) const {
    return getField(columnName);
}

const Cloude::Foundation::SPtrCell &Cloude::Foundation::Store::IDataRecord::getField(
        const std::string &columnName) const {

    auto search = _cellMap.find(columnName);

    if (search == _cellMap.end()) {
        throw Exception::cldeEntityException(columnName + " field is not found");
    }

    return search->second;
}

const Cloude::Foundation::SPtrCell &Cloude::Foundation::Store::IDataRecord::getField(const char *columnName) const {
    std::string columnNameStr(columnName);
    return getField(columnNameStr);
}

bool Cloude::Foundation::Store::IDataRecord::HasCell(const std::string &cellName) {
    auto search = _cellMap.find(cellName);
    auto result = !(search == _cellMap.end());
    return result;
}

unsigned long Cloude::Foundation::Store::IDataRecord::Size() {
    return _cellMap.size();
}

const std::string Cloude::Foundation::Store::IDataRecord::CopyToString() const {

    std::string result;

    auto sptrFieldVector = getFields();

    std::for_each(sptrFieldVector.crbegin(), sptrFieldVector.crend(),
                  [&result](const SPtrCell &field) {
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

Cloude::Foundation::SPtrCellVector Cloude::Foundation::Store::IDataRecord::getFields() const {

    SPtrCellVector fieldVector;

    for (auto pairField : _cellMap) {
        fieldVector.push_back(pairField.second);
    }

    return fieldVector;
}

Cloude::Foundation::SPtrColumnVector Cloude::Foundation::Store::IDataRecord::getColumns() const {

    SPtrColumnVector columnVector;

    for (auto pairField : _cellMap) {
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
