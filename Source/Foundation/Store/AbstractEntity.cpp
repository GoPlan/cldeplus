//
// Created by LE, Duc Anh on 6/16/15.
//

#include "AbstractEntity.h"
#include "Helper/CellHelper.h"
#include "../Exception/CLDEEntityException.h"
#include "../Exception/CLDENonSupportedFunctionException.h"

namespace CLDEPlus {
    namespace Foundation {

        Store::AbstractEntity::AbstractEntity(const Store::AbstractEntity &entity) {

            auto &srcCellsMap = entity.getCellsMap();

            for (auto &srcCellPair : srcCellsMap) {
                auto newCell = Foundation::Store::Helper::CellHelper::CopySPtrCell(srcCellPair.second);
                _cellMap[srcCellPair.first] = newCell;
            }
        }

        Store::AbstractEntity &Store::AbstractEntity::operator=(Store::AbstractEntity const &entity) {

            if (this == &entity)
                return *this;

            _cellMap.clear();

            auto &srcCellsMap = entity.getCellsMap();

            for (auto &srcCellPair : srcCellsMap) {
                auto newCell = Foundation::Store::Helper::CellHelper::CopySPtrCell(srcCellPair.second);
                _cellMap[srcCellPair.first] = newCell;
            }

            return *this;
        }

        void Store::AbstractEntity::setCell(SPtrCell const &cell) {
            _cellMap[cell->getColumn()->getName()] = cell;
        }

        void Store::AbstractEntity::setCell(Cell *ptrCell) {
            SPtrCell sptrCell(ptrCell);
            _cellMap[ptrCell->getColumn()->getName()] = sptrCell;
        }

        void Store::AbstractEntity::setMultiCells(SPtrCellVector const &cellVector) {
            for (auto &sptrField : cellVector) {
                setCell(sptrField);
            }
        }

        void Store::AbstractEntity::setMultiCells(vector<Cell *> const &cellVector) {
            for (auto ptrField : cellVector) {
                setCell(ptrField);
            }
        }

        const SPtrCell &CLDEPlus::Foundation::Store::AbstractEntity::operator[](string const &columnName) const {
            return getCell(columnName);
        }

        const SPtrCell &CLDEPlus::Foundation::Store::AbstractEntity::getCell(string const &columnName) const {

            auto search = _cellMap.find(columnName);

            if (search == _cellMap.end()) {
                string msg{columnName + " is not found in record"};
                throw Exception::CLDEEntityException{msg};
            }

            return search->second;
        }


        bool Store::AbstractEntity::TryGetCell(const string &columnName, SPtrCell &sptrOutCell) const {

            auto search = _cellMap.find(columnName);

            if (search == _cellMap.end()) {
                return false;
            }

            sptrOutCell.reset(search->second.get());

            return true;
        }

        bool Store::AbstractEntity::hasCell(const string &cellName) const {
            auto search = _cellMap.find(cellName);
            auto result = !(search == _cellMap.end());
            return result;
        }

        unsigned long Store::AbstractEntity::Size() const {
            return _cellMap.size();
        }

        Foundation::SPtrCellVector Store::AbstractEntity::getCells() const {

            SPtrCellVector vectorCells;

            for (auto pairField : _cellMap) {
                vectorCells.push_back(pairField.second);
            }

            return vectorCells;
        }

        Foundation::SPtrCellVector Store::AbstractEntity::getCells(const SPtrColumnVector &selectedColumns) const {

            SPtrCellVector vectorCells;

            for (auto column : selectedColumns) {

                auto pairCellIter = _cellMap.find(column->getName());

                if (pairCellIter != _cellMap.cend()) {
                    vectorCells.push_back((*pairCellIter).second);
                }
            }

            return vectorCells;
        }

        Foundation::SPtrColumnVector Store::AbstractEntity::getColumns() const {

            SPtrColumnVector columnVector;

            for (auto pairField : _cellMap) {
                columnVector.push_back(pairField.second->getColumn());
            }

            return columnVector;
        }

        string Store::AbstractEntity::ToString() const {

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
                                  result += field->getValue()->ToString();
                              }
                          });

            return result;
        }

        string Store::AbstractEntity::ToString(const Foundation::Common::IFormatter &formatter) const {
            return formatter.Format(*this);
        }
    }
}

