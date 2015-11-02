//
// Created by LE, Duc Anh on 6/30/15.
//

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_TYPECASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_TYPECASTER_H

#include <memory>
#include "../../Foundation/Data/Value.h"
#include "../../Foundation/Column.h"
#include <unordered_map>

namespace CLDEPlus {
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
                                                         Foundation::Data::SPtrValue const &value) const;

            protected:
                TypeCaster() = default;
            };


            using SPtrCaster = shared_ptr<TypeCaster>;
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_TYPECASTER_H
