//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECONVERTER_H

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class ByteConverter {

                public:
                    ByteConverter() = default;
                    ByteConverter(const ByteConverter &) = default;
                    ByteConverter(ByteConverter &&) = default;
                    ByteConverter &operator=(const ByteConverter &) = default;
                    ByteConverter &operator=(ByteConverter &&) = default;
                    virtual ~ByteConverter() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_BYTECONVERTER_H
