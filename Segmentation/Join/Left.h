//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_LEFT_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_LEFT_H

#include <Foundation/EntityProxy.h>
#include <Segmentation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            class Left {

                Foundation::SPtrColumnVector _lhsComparingColumns;
                Foundation::SPtrColumnVector _rhsComparingColumns;
                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                Left();
                Left(const Left &) = default;
                Left(Left &&) = default;
                Left &operator=(const Left &) = default;
                Left &operator=(Left &&) = default;
                ~Left() = default;

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


#endif //CLOUD_E_PLUS_LEFT_H
