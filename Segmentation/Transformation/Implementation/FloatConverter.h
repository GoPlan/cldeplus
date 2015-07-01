//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_FLOATCONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_FLOATCONVERTER_H

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Implementation {

                class FloatConverter {

                public:
                    FloatConverter() = default;
                    FloatConverter(const FloatConverter &) = default;
                    FloatConverter(FloatConverter &&) = default;
                    FloatConverter &operator=(const FloatConverter &) = default;
                    FloatConverter &operator=(FloatConverter &&) = default;
                    virtual ~FloatConverter() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_FLOATCONVERTER_H
