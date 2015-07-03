//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECASTER_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECASTER_H

#include <memory>
#include <Foundation/Data/Value.h>
#include <Foundation/Column.h>
#include <unordered_map>

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {

            class TypeCaster {

            public:
                TypeCaster(const TypeCaster &) = default;
                TypeCaster(TypeCaster &&) = default;
                TypeCaster &operator=(const TypeCaster &) = default;
                TypeCaster &operator=(TypeCaster &&) = default;
                ~TypeCaster() = default;

                // Locals
                virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                         const Foundation::Data::SPtrValue &value) const;

            protected:
                TypeCaster() = default;
            };


            using SPtrTypeConverter = std::shared_ptr<TypeCaster>;
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECASTER_H
