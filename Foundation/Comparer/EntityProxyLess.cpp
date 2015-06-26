//
// Created by LE, Duc Anh on 6/26/15.
//

#include "EntityProxyLess.h"
#include <Foundation/Type/Comparer/cldeValueComparer.h>

namespace Cloude {
    namespace Foundation {

        bool Comparer::EntityProxyLess::operator()(const SPtrEntityProxy &lhs,
                                                   const SPtrEntityProxy &rhs) const {

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

                if (_less(lhsValue, rhsValue))
                    return true;
            }

            return false;
        }
    }
}

