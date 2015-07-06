//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H

#include <Foundation/EntityProxy.h>
#include <Segmentation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            class Cross {

                Foundation::SPtrColumnVector _lhsComparingColumns;
                Foundation::SPtrColumnVector _rhsComparingColumns;
                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                Cross();
                Cross(const Cross &) = default;
                Cross(Cross &&) = default;
                Cross &operator=(const Cross &) = default;
                Cross &operator=(Cross &&) = default;
                ~Cross() = default;

                // Accessors
                const Foundation::SPtrColumnVector &getCLhsComparingColumns() const { return _lhsComparingColumns; }
                const Foundation::SPtrColumnVector &getCRhsComparingColumns() const { return _rhsComparingColumns; }
                const Segmentation::Transformation::SPtrEntityTransformer &getLhsCTransformer() const { return _sptrLhsTransformer; }
                const Segmentation::Transformation::SPtrEntityTransformer &getRhsCTransformer() const { return _sptrRhsTransformer; }

                Foundation::SPtrColumnVector &LhsComparingColumns() { return _lhsComparingColumns; }
                Foundation::SPtrColumnVector &RhsComparingColumns() { return _rhsComparingColumns; }

                Segmentation::Transformation::SPtrEntityTransformer &LhsTransformer() { return _sptrLhsTransformer; }
                Segmentation::Transformation::SPtrEntityTransformer &RhsTransformer() { return _sptrRhsTransformer; }

                // Locals
                Foundation::SPtrEntityProxySet operator()(const Foundation::SPtrEntityProxySet &lhs,
                                                          const Foundation::SPtrEntityProxySet &rhs) const;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
