//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT16CASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT16CASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class Int16Caster : public TypeCaster {

                public:
                    Int16Caster() = default;
                    Int16Caster(const Int16Caster &) = default;
                    Int16Caster(Int16Caster &&) = default;
                    Int16Caster &operator=(const Int16Caster &) = default;
                    Int16Caster &operator=(Int16Caster &&) = default;
                    virtual ~Int16Caster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT16CASTER_H
