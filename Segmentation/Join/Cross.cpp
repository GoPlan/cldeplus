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

            Foundation::SPtrEntityProxyVector Cross::Join(
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


