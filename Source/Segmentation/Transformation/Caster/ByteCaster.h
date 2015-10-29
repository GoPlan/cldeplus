//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class ByteCaster : public TypeCaster {

                public:
                    ByteCaster() = default;
                    ByteCaster(const ByteCaster &) = default;
                    ByteCaster(ByteCaster &&) = default;
                    ByteCaster &operator=(const ByteCaster &) = default;
                    ByteCaster &operator=(ByteCaster &&) = default;
                    virtual ~ByteCaster() = default;

                    // TypeCaster

                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECASTER_H
