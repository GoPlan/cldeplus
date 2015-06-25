//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCOMPARER_H
#define CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCOMPARER_H

#include <Foundation/Exception/cldeSegmentationException.h>
#include <Foundation/EntityProxy.h>

namespace Cloude {
    namespace Foundation {
        namespace Comparer {

            struct EntityProxyEqual : std::binary_function<SPtrEntityProxy, SPtrEntityProxy, bool> {

                EntityProxyEqual(const SPtrColumnVector &lhsComparingColumns,
                                    const SPtrColumnVector &rhsComparingColumns)
                        : lhsComparingColumns{lhsComparingColumns},
                          rhsComparingColumns{rhsComparingColumns} { };

                const SPtrColumnVector &lhsComparingColumns;
                const SPtrColumnVector &rhsComparingColumns;

                bool operator()(const SPtrEntityProxy &lhs, const SPtrEntityProxy &rhs) const {

                    if (lhsComparingColumns.size() != rhsComparingColumns.size()) {
                        return false;
                    }

                    auto rhsColumnIter = rhsComparingColumns.cbegin();

                    for (auto column : lhsComparingColumns) {

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

#endif //CLOUD_E_PLUS_FOUNDATION_COMPARER_ENTITYPROXYCOMPARER_H
