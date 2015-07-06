//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Store/Helper/CellHelper.h>
#include <Foundation/Store/Comparer/Less.h>
#include <Foundation/Store/Comparer/Compare.h>
#include <Foundation/Store/Comparer/Greater.h>
#include "Right.h"

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            Foundation::SPtrEntityProxyVector Right::Join(
                    const Cloude::Foundation::SPtrEntityProxyVector &lhsVector,
                    const Cloude::Foundation::SPtrEntityProxyVector &rhsVector) const {
                return left.Join(rhsVector, lhsVector);
            }
        }
    }
}

