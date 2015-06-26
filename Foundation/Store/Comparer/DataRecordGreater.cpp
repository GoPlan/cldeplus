//
// Created by LE, Duc Anh on 6/26/15.
//

#include "DataRecordGreater.h"

namespace Cloude {
    namespace Foundation {
        namespace Store {
            bool Comparer::DataRecordGreater::operator()(const Store::SPtrDataRecord &lhs,
                                                         const Store::SPtrDataRecord &rhs) const {

                if (_lhsCmpColumns.size() != _rhsCmpColumns.size()) {
                    return false;
                }

                auto rhsColumnIter = _rhsCmpColumns.cbegin();

                for (auto column : _lhsCmpColumns) {

                    auto &lhsCell = lhs->getCell(column->getName());
                    auto &rhsCell = rhs->getCell((*rhsColumnIter)->getName());

                    ++rhsColumnIter;

                    if (lhsCell->isNull() || rhsCell->isNull())
                        return false;

                    auto &lhsValue = lhsCell->getValue();
                    auto &rhsValue = rhsCell->getValue();

                    if (_greater(lhsValue, rhsValue))
                        return true;
                }

                return false;
            }
        }
    }
}

