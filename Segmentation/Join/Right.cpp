//
// Created by LE, Duc Anh on 6/24/15.
//

#include "Right.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            Foundation::SPtrEntityProxySet Right::JoinSet(
                    const Cloude::Foundation::SPtrEntityProxySet &lhsSet,
                    const Cloude::Foundation::SPtrEntityProxySet &rhsSet) const {
                return left.JoinSet(rhsSet, lhsSet);
            }

            Foundation::SPtrEntityProxyVector Right::JoinVector(
                    const Cloude::Foundation::SPtrEntityProxyVector &lhsVector,
                    const Cloude::Foundation::SPtrEntityProxyVector &rhsVector) const {
                return left.JoinVector(rhsVector, lhsVector);
            }
        }
    }
}

