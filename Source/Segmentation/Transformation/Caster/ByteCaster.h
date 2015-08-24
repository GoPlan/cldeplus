//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECASTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECASTER_H

#include <Segmentation/Transformation/TypeCaster.h>

namespace Cloude {
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


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECASTER_H
