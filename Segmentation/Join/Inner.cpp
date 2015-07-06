//
// Created by LE, Duc Anh on 6/23/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/Store/Comparer/Less.h>
#include <Foundation/Store/Comparer/Compare.h>
#include <Foundation/Store/Comparer/Greater.h>
#include "Inner.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            Inner::Inner() {
                _sptrLhsTransformer = std::make_shared<Segmentation::Transformation::EntityTransformer>();
                _sptrRhsTransformer = std::make_shared<Segmentation::Transformation::EntityTransformer>();
            }

            Foundation::SPtrEntityProxyVector Inner::Join(const Foundation::SPtrEntityProxyVector &lhsVector,
                                                         const Foundation::SPtrEntityProxyVector &rhsVector) const {

                using CellHelper = Foundation::Store::Helper::CellHelper;
                using DataRecordLess = Foundation::Store::Comparer::Less;
                using DataRecordGreater = Foundation::Store::Comparer::Greater;
                using DataRecordCompare = Foundation::Store::Comparer::Compare<>;

                DataRecordCompare compare{_lhsComparingColumns, _lhsComparingColumns};
                DataRecordLess lesser{_lhsComparingColumns, _rhsComparingColumns};
                DataRecordGreater greater{_lhsComparingColumns, _rhsComparingColumns};

                Foundation::SPtrEntityProxyVector vtorProxies;
                auto lhsCurrent = lhsVector.cbegin();
                auto rhsCurrent = rhsVector.cbegin();
                auto lhsEnd = lhsVector.cend();
                auto rhsEnd = rhsVector.cend();

                while (lhsCurrent != lhsEnd && rhsCurrent != rhsEnd) {

                    if (lhsCurrent != lhsEnd && lesser(*lhsCurrent, *rhsCurrent)) {
                        // Ignore
                        ++lhsCurrent;
                        continue;
                    }
                    else if (rhsCurrent != rhsEnd && greater(*lhsCurrent, *rhsCurrent)) {
                        // Ignore
                        ++rhsCurrent;
                        continue;
                    }
                    else {

                        auto rhsTmp = rhsCurrent;
                        auto lhsTmp = lhsCurrent;

                        while (rhsCurrent != rhsEnd && !lesser(*lhsCurrent, *rhsCurrent)) {

                            Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                            _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                            _sptrRhsTransformer->Transform(*rhsCurrent, proxy);

                            vtorProxies.push_back(proxy);
                            ++rhsCurrent;
                        }

                        ++lhsCurrent;

                        if (lhsCurrent != lhsEnd && compare(*lhsTmp, *(lhsCurrent)))
                            rhsCurrent = rhsTmp;
                    }
                }

                return vtorProxies;
            }
        }
    }
}


