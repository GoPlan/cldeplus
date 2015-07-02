//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_VARCHARCONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_VARCHARCONVERTER_H

#include <Segmentation/Transformation/TypeConverter.h>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            namespace Converter {

                class VarCharConverter : public TypeConverter {

                public:
                    VarCharConverter() = default;
                    VarCharConverter(const VarCharConverter &) = default;
                    VarCharConverter(VarCharConverter &&) = default;
                    VarCharConverter &operator=(const VarCharConverter &) = default;
                    VarCharConverter &operator=(VarCharConverter &&) = default;
                    virtual ~VarCharConverter() = default;

                    // TypeConverter
                    virtual Foundation::Data::SPtrValue
                            Convert(const Foundation::SPtrColumn &column,
                                    const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_VARCHARCONVERTER_H
