//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class Cross {

                    SPtrColumnVector _lhsComparingColumns;
                    SPtrColumnVector _rhsComparingColumns;
                    Transformation::SPtrEntityTransformer _sptrTransformer;

                public:
                    Cross() = default;
                    Cross(const Cross &) = default;
                    Cross(Cross &&) = default;
                    Cross &operator=(const Cross &) = default;
                    Cross &operator=(Cross &&) = default;
                    ~Cross() = default;

                    // Accessors
                    const SPtrColumnVector &getCLhsComparingColumns() const { return _lhsComparingColumns; }
                    const SPtrColumnVector &getCRhsComparingColumns() const { return _rhsComparingColumns; }
                    const Transformation::SPtrEntityTransformer &getCTransformer() const { return _sptrTransformer; }

                    SPtrColumnVector &getLhsComparingColumns() { return _lhsComparingColumns; }
                    SPtrColumnVector &getRhsComparingColumns() { return _rhsComparingColumns; }
                    Transformation::SPtrEntityTransformer &getTransformer() { return _sptrTransformer; }

                    // Locals
                    SPtrEntityProxySet operator()(const SPtrEntityProxySet &lhs, const SPtrEntityProxySet &rhs) const;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
