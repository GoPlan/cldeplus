//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT32CASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT32CASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class UInt32Caster : public TypeCaster {

                public:
                    UInt32Caster() = default;
                    UInt32Caster(const UInt32Caster &) = default;
                    UInt32Caster(UInt32Caster &&) = default;
                    UInt32Caster &operator=(const UInt32Caster &) = default;
                    UInt32Caster &operator=(UInt32Caster &&) = default;
                    virtual ~UInt32Caster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT32CASTER_H
