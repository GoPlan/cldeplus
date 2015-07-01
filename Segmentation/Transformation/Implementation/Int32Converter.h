//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_INT32CONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_INT32CONVERTER_H

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Implementation {

                class Int32Converter {

                public:
                    Int32Converter() = default;
                    Int32Converter(const Int32Converter &) = default;
                    Int32Converter(Int32Converter &&) = default;
                    Int32Converter &operator=(const Int32Converter &) = default;
                    Int32Converter &operator=(Int32Converter &&) = default;
                    virtual ~Int32Converter() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_INT32CONVERTER_H
