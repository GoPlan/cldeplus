//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CASTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CASTER_H

#include <Segmentation/Transformation/TypeCaster.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class Int32Caster : public TypeCaster {

                public:
                    Int32Caster() = default;
                    Int32Caster(const Int32Caster &) = default;
                    Int32Caster(Int32Caster &&) = default;
                    Int32Caster &operator=(const Int32Caster &) = default;
                    Int32Caster &operator=(Int32Caster &&) = default;
                    virtual ~Int32Caster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CASTER_H
