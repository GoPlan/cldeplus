//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT64CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT64CONVERTER_H

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Implementation {

                class UInt64Converter {

                public:
                    UInt64Converter() = default;
                    UInt64Converter(const UInt64Converter &) = default;
                    UInt64Converter(UInt64Converter &&) = default;
                    UInt64Converter &operator=(const UInt64Converter &) = default;
                    UInt64Converter &operator=(UInt64Converter &&) = default;
                    virtual ~UInt64Converter() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_UINT64CONVERTER_H
