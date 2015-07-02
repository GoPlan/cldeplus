//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_DOUBLECONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_DOUBLECONVERTER_H

#include "../TypeConverter.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class DoubleConverter : public TypeConverter {

                public:
                    DoubleConverter() = default;
                    DoubleConverter(const DoubleConverter &) = default;
                    DoubleConverter(DoubleConverter &&) = default;
                    DoubleConverter &operator=(const DoubleConverter &) = default;
                    DoubleConverter &operator=(DoubleConverter &&) = default;
                    virtual ~DoubleConverter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(Foundation::Data::ValueType dataType,
                                    const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_DOUBLECONVERTER_H
