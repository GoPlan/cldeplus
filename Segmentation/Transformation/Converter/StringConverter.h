//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_STRINGCONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_STRINGCONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class StringConverter : public TypeConverter {

                public:
                    StringConverter() = default;
                    StringConverter(const StringConverter &) = default;
                    StringConverter(StringConverter &&) = default;
                    StringConverter &operator=(const StringConverter &) = default;
                    StringConverter &operator=(StringConverter &&) = default;
                    virtual ~StringConverter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value)
                            const override;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_STRINGCONVERTER_H
