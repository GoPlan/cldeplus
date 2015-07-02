//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT64CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT64CONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class Int64Converter : public TypeConverter {

                public:
                    Int64Converter() = default;
                    Int64Converter(const Int64Converter &) = default;
                    Int64Converter(Int64Converter &&) = default;
                    Int64Converter &operator=(const Int64Converter &) = default;
                    Int64Converter &operator=(Int64Converter &&) = default;
                    virtual ~Int64Converter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(const Foundation::SPtrColumn &column,
                                    const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT64CONVERTER_H
