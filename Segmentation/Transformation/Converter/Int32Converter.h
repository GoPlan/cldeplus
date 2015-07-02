//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class Int32Converter : public TypeConverter {

                public:
                    Int32Converter() = default;
                    Int32Converter(const Int32Converter &) = default;
                    Int32Converter(Int32Converter &&) = default;
                    Int32Converter &operator=(const Int32Converter &) = default;
                    Int32Converter &operator=(Int32Converter &&) = default;
                    virtual ~Int32Converter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(const Foundation::SPtrColumn &column,
                                    const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_INT32CONVERTER_H
