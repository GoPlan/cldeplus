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

            struct TypeConverter {
                virtual Foundation::Data::SPtrValue Convert(const Foundation::SPtrColumn &column,
                                                            const Foundation::Data::SPtrValue &value);
            };

            using SPtrTypeConverter = std::shared_ptr<TypeConverter>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTER_H
