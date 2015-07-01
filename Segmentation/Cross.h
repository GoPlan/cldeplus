//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H

#include <Foundation/EntityProxy.h>
#include <Segmentation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Segmentation {
        class Cross {

            Foundation::SPtrColumnVector _lhsComparingColumns;
            Foundation::SPtrColumnVector _rhsComparingColumns;
            Transformation::SPtrEntityTransformer _sptrTransformer;

        public:
            Cross() = default;
            Cross(const Cross &) = default;
            Cross(Cross &&) = default;
            Cross &operator=(const Cross &) = default;
            Cross &operator=(Cross &&) = default;
            ~Cross() = default;

            // Accessors
            const Foundation::SPtrColumnVector &getCLhsComparingColumns() const { return _lhsComparingColumns; }
            const Foundation::SPtrColumnVector &getCRhsComparingColumns() const { return _rhsComparingColumns; }
            const Segmentation::Transformation::SPtrEntityTransformer &getCTransformer() const { return _sptrTransformer; }

            Foundation::SPtrColumnVector &getLhsComparingColumns() { return _lhsComparingColumns; }
            Foundation::SPtrColumnVector &getRhsComparingColumns() { return _rhsComparingColumns; }
            Segmentation::Transformation::SPtrEntityTransformer &getTransformer() { return _sptrTransformer; }

            // Locals
            Foundation::SPtrEntityProxySet operator()(const Foundation::SPtrEntityProxySet &lhs,
                                                      const Foundation::SPtrEntityProxySet &rhs) const;
        };
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
