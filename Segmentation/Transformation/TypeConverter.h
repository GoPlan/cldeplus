//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTER_H

#include <memory>
#include <Foundation/Data/Value.h>
#include <Foundation/Column.h>
#include <unordered_map>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {

            class TypeConverter {

            public:
                TypeConverter(const TypeConverter &) = default;
                TypeConverter(TypeConverter &&) = default;
                TypeConverter &operator=(const TypeConverter &) = default;
                TypeConverter &operator=(TypeConverter &&) = default;
                ~TypeConverter() = default;

                // Locals
                virtual Foundation::Data::SPtrValue Convert(Foundation::Data::ValueType dataType,
                                                            const Foundation::Data::SPtrValue &value) const;

            protected:
                TypeConverter() = default;
            };


            using SPtrTypeConverter = std::shared_ptr<TypeConverter>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTER_H
