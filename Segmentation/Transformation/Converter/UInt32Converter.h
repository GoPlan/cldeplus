//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT32CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT32CONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class UInt32Converter : public TypeConverter {

                public:
                    UInt32Converter() = default;
                    UInt32Converter(const UInt32Converter &) = default;
                    UInt32Converter(UInt32Converter &&) = default;
                    UInt32Converter &operator=(const UInt32Converter &) = default;
                    UInt32Converter &operator=(UInt32Converter &&) = default;
                    virtual ~UInt32Converter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value)
                            const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT32CONVERTER_H
