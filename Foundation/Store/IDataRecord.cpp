//
// Created by LE, Duc Anh on 6/16/15.
//

#include <Foundation/Exception/cldeEntityException.h>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "IDataRecord.h"

namespace Cloude {
    namespace Foundation {

        void Store::IDataRecord::setCell(const SPtrCell &cell) {
            _cellMap[cell->getColumn()->getName()] = cell;
        }

        void Store::IDataRecord::setCell(Cell *ptrCell) {
            SPtrCell sptrCell(ptrCell);
            _cellMap[ptrCell->getColumn()->getName()] = sptrCell;
        }

        void Store::IDataRecord::setMultiCells(const SPtrCellVector &cellVector) {
            for (auto &sptrField : cellVector) {
                setCell(sptrField);
            }
        }

        void Store::IDataRecord::setMultiCells(const std::vector<Cell *> &cellVector) {
            for (auto ptrField : cellVector) {
                setCell(ptrField);
            }
        }

        const SPtrCell &Cloude::Foundation::Store::IDataRecord::operator[](const std::string &columnName) const {
            return getCell(columnName);
        }

        const SPtrCell &Cloude::Foundation::Store::IDataRecord::getCell(const std::string &columnName) const {

            auto search = _cellMap.find(columnName);

            if (search == _cellMap.end()) {
                std::string msg{columnName + " is not found in record"};
                throw Exception::cldeEntityException{msg};
            }

            return search->second;
        }


        bool Store::IDataRecord::TryGetCell(const std::string &columnName, SPtrCell &sptrOutCell) const {

            auto search = _cellMap.find(columnName);

            if (search == _cellMap.end()) {
                return false;
            }

            sptrOutCell.reset(search->second.get());

            return true;
        }

        bool Store::IDataRecord::hasCell(const std::string &cellName) {
            auto search = _cellMap.find(cellName);
            auto result = !(search == _cellMap.end());
            return result;
        }

        unsigned long Store::IDataRecord::Size() {
            return _cellMap.size();
        }

        Foundation::SPtrCellVector Store::IDataRecord::getCells() const {

            SPtrCellVector vectorCells;

            for (auto pairField : _cellMap) {
                vectorCells.push_back(pairField.second);
            }

            return vectorCells;
        }

        Foundation::SPtrCellVector Store::IDataRecord::getCells(const SPtrColumnVector &selectedColumns) const {

            SPtrCellVector vectorCells;

            for (auto column : selectedColumns) {

                auto pairCellIter = _cellMap.find(column->getName());

                if (pairCellIter != _cellMap.cend()) {
                    vectorCells.push_back((*pairCellIter).second);
                }
            }

            return vectorCells;
        }

        Foundation::SPtrColumnVector Store::IDataRecord::getColumns() const {

            SPtrColumnVector columnVector;

            for (auto pairField : _cellMap) {
                columnVector.push_back(pairField.second->getColumn());
            }

            return columnVector;
        }

        const std::string &Store::IDataRecord::ToString() const {
            std::string msg{"ToString is not supported, use CopyToString intead"};
            throw Exception::cldeNonSupportedFunctionException{msg};
        }

        const char *Store::IDataRecord::ToCString() const {
            std::string msg{"ToCString is not supported, use CopyToString intead"};
            throw Exception::cldeNonSupportedFunctionException{msg};
        }

        const std::string Store::IDataRecord::CopyToString() const {

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

