//
// Created by LE, Duc Anh on 6/16/15.
//

#include <Foundation/Exception/cldeEntityException.h>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "AbstractEntity.h"

namespace Cloude {
    namespace Foundation {

        void Store::AbstractEntity::setCell(const SPtrCell &cell) {
            _cellMap[cell->getColumn()->getName()] = cell;
        }

        void Store::AbstractEntity::setCell(Cell *ptrCell) {
            SPtrCell sptrCell(ptrCell);
            _cellMap[ptrCell->getColumn()->getName()] = sptrCell;
        }

        void Store::AbstractEntity::setMultiCells(const SPtrCellVector &cellVector) {
            for (auto &sptrField : cellVector) {
                setCell(sptrField);
            }
        }

        void Store::AbstractEntity::setMultiCells(const std::vector<Cell *> &cellVector) {
            for (auto ptrField : cellVector) {
                setCell(ptrField);
            }
        }

        const SPtrCell &Cloude::Foundation::Store::AbstractEntity::operator[](const std::string &columnName) const {
            return getCell(columnName);
        }

        const SPtrCell &Cloude::Foundation::Store::AbstractEntity::getCell(const std::string &columnName) const {

            auto search = _cellMap.find(columnName);

            if (search == _cellMap.end()) {
                std::string msg{columnName + " is not found in record"};
                throw Exception::cldeEntityException{msg};
            }

            return search->second;
        }


        bool Store::AbstractEntity::TryGetCell(const std::string &columnName, SPtrCell &sptrOutCell) const {

            auto search = _cellMap.find(columnName);

            if (search == _cellMap.end()) {
                return false;
            }

            sptrOutCell.reset(search->second.get());

            return true;
        }

        bool Store::AbstractEntity::hasCell(const std::string &cellName) {
            auto search = _cellMap.find(cellName);
            auto result = !(search == _cellMap.end());
            return result;
        }

        unsigned long Store::AbstractEntity::Size() {
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

        const std::string &Store::AbstractEntity::ToString() const {
            std::string msg{"ToString is not supported, use CopyToString intead"};
            throw Exception::cldeNonSupportedFunctionException{msg};
        }

        const char *Store::AbstractEntity::ToCString() const {
            std::string msg{"ToCString is not supported, use CopyToString intead"};
            throw Exception::cldeNonSupportedFunctionException{msg};
        }

        const std::string Store::AbstractEntity::CopyToString() const {

            std::string result;

            auto sptrFieldVector = getCells();

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
    }
}

