//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT16CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT16CONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class UInt16Converter : public TypeConverter {

                public:
                    UInt16Converter() = default;
                    UInt16Converter(const UInt16Converter &) = default;
                    UInt16Converter(UInt16Converter &&) = default;
                    UInt16Converter &operator=(const UInt16Converter &) = default;
                    UInt16Converter &operator=(UInt16Converter &&) = default;
                    virtual ~UInt16Converter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value)
                            const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT16CONVERTER_H
