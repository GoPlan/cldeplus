//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCONVERTER_H

#include "../TypeConverter.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class FloatConverter : public TypeConverter {

                public:
                    FloatConverter() = default;
                    FloatConverter(const FloatConverter &) = default;
                    FloatConverter(FloatConverter &&) = default;
                    FloatConverter &operator=(const FloatConverter &) = default;
                    FloatConverter &operator=(FloatConverter &&) = default;
                    virtual ~FloatConverter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value)
                            const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCONVERTER_H
