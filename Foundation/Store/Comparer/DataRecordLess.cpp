//
// Created by LE, Duc Anh on 6/26/15.
//

#include "DataRecordLess.h"

namespace Cloude {
    namespace Foundation {
        namespace Store {
            bool Comparer::DataRecordLess::operator()(const Store::AbstractionEntity &lhs,
                                                      const Store::AbstractionEntity &rhs) const {

                if (_lhsCmpColumns.size() != _rhsCmpColumns.size()) {
                    return false;
                }

                auto rhsColumnIter = _rhsCmpColumns.cbegin();

                for (auto column : _lhsCmpColumns) {

                    auto &lhsCell = lhs.getCell(column->getName());
                    auto &rhsCell = rhs.getCell((*rhsColumnIter)->getName());

                    ++rhsColumnIter;

                    if (lhsCell->isNull() || rhsCell->isNull())
                        return false;

                    auto &lhsValue = lhsCell->getValue();
                    auto &rhsValue = rhsCell->getValue();

                    if (_less(lhsValue, rhsValue))
                        return true;
                }

                return false;
            }
        }
    }
}

