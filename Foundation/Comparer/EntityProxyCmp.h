//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCMP_H
#define CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCMP_H

#include <Foundation/Exception/cldeSegmentationException.h>
#include <Foundation/EntityProxy.h>


namespace Cloude {
    namespace Foundation {
        namespace Comparer {

            struct EntityProxyCmp : std::binary_function<SPtrEntityProxy, SPtrEntityProxy, bool> {

                EntityProxyCmp(const SPtrColumnVector &lhsColumns, const SPtrColumnVector &rhsColumns)
                        : lhsColumns{lhsColumns}, rhsColumns{rhsColumns} { };

                const SPtrColumnVector &lhsColumns;
                const SPtrColumnVector &rhsColumns;

                bool operator()(const SPtrEntityProxy &lhs, const SPtrEntityProxy &rhs) const {

                    if (lhsColumns.size() != rhsColumns.size()) {
                        return false;
                    }

                    auto rhsColumnIter = rhsColumns.cbegin();

                    for (auto column : lhsColumns) {

                        auto &lhsCell = lhs->getCell(column->getName());
                        auto &rhsCell = rhs->getCell((*rhsColumnIter)->getName());

                        ++rhsColumnIter;

                        if (lhsCell->isNull() || rhsCell->isNull())
                            return false;

                        auto &lhsValue = lhsCell->getValue();
                        auto &rhsValue = rhsCell->getValue();

                        auto lhsPtr = static_cast<const Cloude::Foundation::Common::IEquatable *>(lhsValue.get());
                        auto rhsPtr = static_cast<const Cloude::Foundation::Common::IEquatable *>(rhsValue.get());

                        if (!lhsPtr->Equal(*rhsPtr))
                            return false;

                    }

                    return true;
                };
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCMP_H
