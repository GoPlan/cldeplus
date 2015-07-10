//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CASTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CASTER_H

#include <Segmentation/Transformation/TypeCaster.h>

namespace Cloude {
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


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CASTER_H