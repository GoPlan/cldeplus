//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include "Cross.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            Cross::Cross() {
                _sptrLhsTransformer = std::make_shared<Segmentation::Transformation::EntityTransformer>();
                _sptrRhsTransformer = std::make_shared<Segmentation::Transformation::EntityTransformer>();
            }

            Foundation::SPtrEntityProxySet Cross::JoinSet(const Foundation::SPtrEntityProxySet &lhsSet,
                                                          const Foundation::SPtrEntityProxySet &rhsSet) const {

                Foundation::SPtrEntityProxySet setProxies;

                auto lhsCurrent = lhsSet.begin();
                auto rhsCurrent = rhsSet.begin();

                auto lhsEnd = lhsSet.end();
                auto rhsEnd = rhsSet.end();

                while (lhsCurrent != lhsEnd) {

                    while (rhsCurrent != rhsEnd) {

                        Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                        _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                        _sptrRhsTransformer->Transform(*rhsCurrent, proxy);

                        setProxies.insert(proxy);

                        ++rhsCurrent;
                    }

                    rhsCurrent = rhsSet.begin();
                    ++lhsCurrent;
                }

                return setProxies;
            }

            Foundation::SPtrEntityProxyVector Cross::JoinVector(
                    const Foundation::SPtrEntityProxyVector &lhsVector,
                    const Foundation::SPtrEntityProxyVector &rhsVector) const {

                Foundation::SPtrEntityProxyVector vectorProxies;

                auto lhsCurrent = lhsVector.begin();
                auto rhsCurrent = rhsVector.begin();

                auto lhsEnd = lhsVector.end();
                auto rhsEnd = rhsVector.end();

                while (lhsCurrent != lhsEnd) {

                    while (rhsCurrent != rhsEnd) {

                        Foundation::SPtrEntityProxy proxy = std::make_shared<Foundation::EntityProxy>();
                        _sptrLhsTransformer->Transform(*lhsCurrent, proxy);
                        _sptrRhsTransformer->Transform(*rhsCurrent, proxy);

                        vectorProxies.push_back(proxy);

                        ++rhsCurrent;
                    }

                    rhsCurrent = rhsVector.begin();
                    ++lhsCurrent;
                }

                return vectorProxies;
            }
        }
    }
}


