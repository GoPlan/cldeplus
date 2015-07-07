//
// Created by LE, Duc Anh on 7/7/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_JOIN_FULL_H
#define CLOUD_E_PLUS_SEGMENTATION_JOIN_FULL_H

#include <Segmentation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Segmentation {
        namespace Join {

            class Full {

                Foundation::SPtrColumnVector _lhsComparingColumns{};
                Foundation::SPtrColumnVector _rhsComparingColumns{};
                Transformation::SPtrEntityTransformer _sptrLhsTransformer;
                Transformation::SPtrEntityTransformer _sptrRhsTransformer;

            public:
                Full();
                Full(const Full &) = default;
                Full(Full &&) = default;
                Full &operator=(const Full &) = default;
                Full &operator=(Full &&) = default;
                virtual ~Full() = default;

                // Accessors
                const Foundation::SPtrColumnVector &getCLhsComparingColumns() const { return _lhsComparingColumns; }
                const Foundation::SPtrColumnVector &getCRhsComparingColumns() const { return _rhsComparingColumns; }
                const Segmentation::Transformation::SPtrEntityTransformer &getLhsCTransformer() const { return _sptrLhsTransformer; }
                const Segmentation::Transformation::SPtrEntityTransformer &getRhsCTransformer() const { return _sptrRhsTransformer; }

                // Mutators
                Foundation::SPtrColumnVector &LhsComparingColumns() { return _lhsComparingColumns; }
                Foundation::SPtrColumnVector &RhsComparingColumns() { return _rhsComparingColumns; }
                Segmentation::Transformation::SPtrEntityTransformer &LhsTransformer() { return _sptrLhsTransformer; }
                Segmentation::Transformation::SPtrEntityTransformer &RhsTransformer() { return _sptrRhsTransformer; }

                // Locals
                Foundation::SPtrEntityProxyVector Join(const Foundation::SPtrEntityProxyVector &lhsVector,
                                                       const Foundation::SPtrEntityProxyVector &rhsVector) const;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_JOIN_FULL_H
