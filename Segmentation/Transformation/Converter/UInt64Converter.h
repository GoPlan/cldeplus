//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class UInt64Converter : public TypeConverter {

                public:
                    UInt64Converter() = default;
                    UInt64Converter(const UInt64Converter &) = default;
                    UInt64Converter(UInt64Converter &&) = default;
                    UInt64Converter &operator=(const UInt64Converter &) = default;
                    UInt64Converter &operator=(UInt64Converter &&) = default;
                    virtual ~UInt64Converter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(const Foundation::SPtrColumn &column,
                                    const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_UINT64CONVERTER_H
