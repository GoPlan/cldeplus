//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_DOUBLECONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_DOUBLECONVERTER_H

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Implementation {

                class DoubleConverter {

                public:
                    DoubleConverter() = default;
                    DoubleConverter(const DoubleConverter &) = default;
                    DoubleConverter(DoubleConverter &&) = default;
                    DoubleConverter &operator=(const DoubleConverter &) = default;
                    DoubleConverter &operator=(DoubleConverter &&) = default;
                    virtual ~DoubleConverter() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_IMPLEMENTATION_DOUBLECONVERTER_H
