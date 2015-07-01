//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT32CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT32CONVERTER_H

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Implementation {

                class UInt32Converter {

                public:
                    UInt32Converter() = default;
                    UInt32Converter(const UInt32Converter &) = default;
                    UInt32Converter(UInt32Converter &&) = default;
                    UInt32Converter &operator=(const UInt32Converter &) = default;
                    UInt32Converter &operator=(UInt32Converter &&) = default;
                    virtual ~UInt32Converter() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT32CONVERTER_H
