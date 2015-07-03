//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_STRINGCASTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_STRINGCASTER_H

#include <Segmentation/Transformation/TypeCaster.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class StringCaster : public TypeCaster {

                public:
                    StringCaster() = default;
                    StringCaster(const StringCaster &) = default;
                    StringCaster(StringCaster &&) = default;
                    StringCaster &operator=(const StringCaster &) = default;
                    StringCaster &operator=(StringCaster &&) = default;
                    virtual ~StringCaster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_STRINGCASTER_H
