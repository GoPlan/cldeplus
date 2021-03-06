/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCASTER_H
#define CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCASTER_H

#include "../TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            namespace Caster {

                class FloatCaster : public TypeCaster {

                public:
                    FloatCaster() = default;
                    FloatCaster(const FloatCaster &) = default;
                    FloatCaster(FloatCaster &&) = default;
                    FloatCaster &operator=(const FloatCaster &) = default;
                    FloatCaster &operator=(FloatCaster &&) = default;
                    virtual ~FloatCaster() = default;

                    // TypeCaster
                    virtual Foundation::Data::SPtrValue Cast(Foundation::Data::ValueType dataType,
                                                             const Foundation::Data::SPtrValue &value) const override;
                };
            }
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_TRANSFORMATION_CONVERTER_FLOATCASTER_H
