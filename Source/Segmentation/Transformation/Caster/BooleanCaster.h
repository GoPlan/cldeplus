//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BOOLEANCASTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BOOLEANCASTER_H

#include <Segmentation/Transformation/TypeCaster.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class BooleanCaster : public TypeCaster {

                public:
                    BooleanCaster() = default;
                    BooleanCaster(const BooleanCaster &) = default;
                    BooleanCaster(BooleanCaster &&) = default;
                    BooleanCaster &operator=(const BooleanCaster &) = default;
                    BooleanCaster &operator=(BooleanCaster &&) = default;
                    virtual ~BooleanCaster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BOOLEANCASTER_H
