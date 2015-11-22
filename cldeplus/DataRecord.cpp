/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "DataRecord.h"
#include "Store/Helper/CellHelper.h"
#include "EntityException.h"

namespace CLDEPlus {
    
    DataRecord::DataRecord(const DataRecord &entity) {

        auto &srcCellsMap = entity.getCellsMap();

        for (auto &srcCellPair : srcCellsMap) {
            auto newCell = Store::Helper::CellHelper::CopySPtrCell(srcCellPair.second);
            _cellMap[srcCellPair.first] = newCell;
        }
    }

    DataRecord &DataRecord::operator=(DataRecord const &entity) {

        if (this == &entity)
            return *this;

        _cellMap.clear();

        auto &srcCellsMap = entity.getCellsMap();

        for (auto &srcCellPair : srcCellsMap) {
            auto newCell = Store::Helper::CellHelper::CopySPtrCell(srcCellPair.second);
            _cellMap[srcCellPair.first] = newCell;
        }

        return *this;
    }

    void DataRecord::setCell(SPtrCell const &cell) {
        _cellMap[cell->getColumn()->getName()] = cell;
    }

    void DataRecord::setCell(Cell *ptrCell) {
        SPtrCell sptrCell(ptrCell);
        _cellMap[ptrCell->getColumn()->getName()] = sptrCell;
    }

    void DataRecord::setMultiCells(SPtrCellVector const &cellVector) {
        for (auto &sptrField : cellVector) {
            setCell(sptrField);
        }
    }

    void DataRecord::setMultiCells(vector<Cell *> const &cellVector) {
        for (auto ptrField : cellVector) {
            setCell(ptrField);
        }
    }

    const SPtrCell &DataRecord::operator[](string const &columnName) const {
        return getCell(columnName);
    }

    const SPtrCell &DataRecord::getCell(string const &columnName) const {

        auto search = _cellMap.find(columnName);

        if (search == _cellMap.end()) {
            string msg{columnName + " is not found in record"};
            throw EntityException{msg};
        }

        return search->second;
    }


    bool DataRecord::TryGetCell(const string &columnName, SPtrCell &sptrOutCell) const {

        auto search = _cellMap.find(columnName);

        if (search == _cellMap.end()) {
            return false;
        }

        sptrOutCell.reset(search->second.get());

        return true;
    }

    bool DataRecord::hasCell(const string &cellName) const {
        auto search = _cellMap.find(cellName);
        auto result = !(search == _cellMap.end());
        return result;
    }

    unsigned long DataRecord::Size() const {
        return _cellMap.size();
    }

    SPtrCellVector DataRecord::getCells() const {

        SPtrCellVector vectorCells;

        for (auto pairField : _cellMap) {
            vectorCells.push_back(pairField.second);
        }

        return vectorCells;
    }

    SPtrCellVector DataRecord::getCells(const SPtrColumnVector &selectedColumns) const {

        SPtrCellVector vectorCells;

        for (auto column : selectedColumns) {

            auto pairCellIter = _cellMap.find(column->getName());

            if (pairCellIter != _cellMap.cend()) {
                vectorCells.push_back((*pairCellIter).second);
            }
        }

        return vectorCells;
    }

    SPtrColumnVector DataRecord::getColumns() const {

        SPtrColumnVector columnVector;

        for (auto pairField : _cellMap) {
            columnVector.push_back(pairField.second->getColumn());
        }

        return columnVector;
    }

    string DataRecord::CopyToString() const {

        string result;

        auto sptrFieldVector = getCells();

        std::for_each(sptrFieldVector.crbegin(), sptrFieldVector.crend(),
                      [&result](const SPtrCell &field) {
                          if (result.length() != 0) {
                              result += " | ";
                          }

                          if (field->isNull()) {
                              result += "null";
                          }
                          else {
                              result += field->getValue()->CopyToString();
                          }
                      });

        return result;
    }

    string DataRecord::CopyToString(const IFormatter &formatter) const {
        return formatter.Format(*this);
    }
}

