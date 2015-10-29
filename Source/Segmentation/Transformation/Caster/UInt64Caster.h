//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class UInt64Caster : public TypeCaster {

                public:
                    UInt64Caster() = default;
                    UInt64Caster(const UInt64Caster &) = default;
                    UInt64Caster(UInt64Caster &&) = default;
                    UInt64Caster &operator=(const UInt64Caster &) = default;
                    UInt64Caster &operator=(UInt64Caster &&) = default;
                    virtual ~UInt64Caster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CASTER_H
