//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT64CASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT64CASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class Int64Caster : public TypeCaster {

                public:
                    Int64Caster() = default;
                    Int64Caster(const Int64Caster &) = default;
                    Int64Caster(Int64Caster &&) = default;
                    Int64Caster &operator=(const Int64Caster &) = default;
                    Int64Caster &operator=(Int64Caster &&) = default;
                    virtual ~Int64Caster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT64CASTER_H
