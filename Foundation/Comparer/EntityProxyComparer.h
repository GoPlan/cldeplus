//
// Created by LE, Duc Anh on 6/25/15.
//

#ifndef CLOUD_E_PLUS_ENTITYPROXYCOMPARER_H
#define CLOUD_E_PLUS_ENTITYPROXYCOMPARER_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Exception/cldeEntityException.h>
#include <Foundation/Type/Comparer/cldeValueComparer.h>
#include "RecordComparisonResult.h"

namespace Cloude {
    namespace Foundation {
        namespace Comparer {

            struct EntityProxyComparer {

                const SPtrColumnVector &lhsComparingColumns;
                const SPtrColumnVector &rhsComparingColumns;

                EntityProxyComparer(const SPtrColumnVector lhsColumns, const SPtrColumnVector rhsColumns)
                        : lhsComparingColumns{lhsColumns}, rhsComparingColumns{rhsColumns} { };

                RecCmpRes operator()(const SPtrEntityProxy &lhs, const SPtrEntityProxy &rhs) const {

                    RecCmpRes result{};

                    if (lhsComparingColumns.size() > rhsComparingColumns.size()) {
                        std::string msg{"Lhs phrase has comparing column size larger than Rhs"};
                        throw Exception::cldeEntityException{msg};
                    }

                    auto rhsColumnIter = rhsComparingColumns.cbegin();

                    for (auto column : lhsComparingColumns) {

                        const SPtrCell &lhsCell = lhs->getCell(column->getName());
                        const SPtrCell &rhsCell = rhs->getCell((*rhsColumnIter)->getName());

                        ++rhsColumnIter;

                        if (lhsCell->isNull()) {
                            result.result = -1;
                            return result;
                        }

                        if (rhsCell->isNull()) {
                            result.result = 1;
                            return result;
                        }

                        const Type::SPtrValue &lhsValue = lhsCell->getValue();
                        const Type::SPtrValue &rhsValue = rhsCell->getValue();

                        auto valueCmpRes = Type::Comparer::cldeValueComparer::Compare(lhsValue, rhsValue);

                        switch (valueCmpRes) {
                            case Type::Comparer::ValueComparingResult::LhsValueIsGreater:
                                result.result = 1;
                                break;
                            case Type::Comparer::ValueComparingResult::RhsValueIsGreater:
                                result.result = -1;
                                break;
                            case Type::Comparer::ValueComparingResult::Equal:
                                result.result = 0;
                                break;
                        }

                        if (result.result != 0) return result;
                    }

                    return result;
                }
            };
        }
    }
}


#endif //CLOUD_E_PLUS_ENTITYPROXYCOMPARER_H
