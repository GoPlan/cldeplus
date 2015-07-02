//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BOOLEANCONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BOOLEANCONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class BooleanConverter : public TypeConverter {

                public:
                    BooleanConverter() = default;
                    BooleanConverter(const BooleanConverter &) = default;
                    BooleanConverter(BooleanConverter &&) = default;
                    BooleanConverter &operator=(const BooleanConverter &) = default;
                    BooleanConverter &operator=(BooleanConverter &&) = default;
                    virtual ~BooleanConverter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(Foundation::Data::ValueType dataType,
                                    const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BOOLEANCONVERTER_H
