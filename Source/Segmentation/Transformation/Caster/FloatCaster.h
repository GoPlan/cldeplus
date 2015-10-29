//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class FloatCaster : public TypeCaster {

                public:
                    FloatCaster() = default;
                    FloatCaster(const FloatCaster &) = default;
                    FloatCaster(FloatCaster &&) = default;
                    FloatCaster &operator=(const FloatCaster &) = default;
                    FloatCaster &operator=(FloatCaster &&) = default;
                    virtual ~FloatCaster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCASTER_H
