//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT16CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT16CONVERTER_H

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Implementation {

                class UInt16Converter {

                public:
                    UInt16Converter() = default;
                    UInt16Converter(const UInt16Converter &) = default;
                    UInt16Converter(UInt16Converter &&) = default;
                    UInt16Converter &operator=(const UInt16Converter &) = default;
                    UInt16Converter &operator=(UInt16Converter &&) = default;
                    virtual ~UInt16Converter() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT16CONVERTER_H
