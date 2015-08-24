//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_DOUBLECASTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_DOUBLECASTER_H

#include "../TypeCaster.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class DoubleCaster : public TypeCaster {

                public:
                    DoubleCaster() = default;
                    DoubleCaster(const DoubleCaster &) = default;
                    DoubleCaster(DoubleCaster &&) = default;
                    DoubleCaster &operator=(const DoubleCaster &) = default;
                    DoubleCaster &operator=(DoubleCaster &&) = default;
                    virtual ~DoubleCaster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_DOUBLECASTER_H
