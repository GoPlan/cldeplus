//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
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


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CASTER_H
