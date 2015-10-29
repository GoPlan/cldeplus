//
// Created by LE, Duc Anh on 6/26/15.
//

#include "Less.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Store {

            bool Comparer::Less::operator()(const Store::SPtrDataRecord &lhs,
                                            const Store::SPtrDataRecord &rhs) const {

                if (_lhsCmpColumns.size() != _rhsCmpColumns.size()) {
                    return false;
                }

                auto rhsColumnIter = _rhsCmpColumns.begin();

                for (auto column : _lhsCmpColumns) {

                    auto &lhsCell = lhs->getCell(column->getName());
                    auto &rhsCell = rhs->getCell((*rhsColumnIter)->getName());

                    ++rhsColumnIter;

                    if (lhsCell->isNull() || rhsCell->isNull())
                        return false;

                    auto &lhsValue = lhsCell->getValue();
                    auto &rhsValue = rhsCell->getValue();

                    if (!_equal(lhsValue, rhsValue))
                        return _less(lhsValue, rhsValue);
                }

                return false;
            }
        }
    }
}

