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

#ifndef CLDEPLUS_SEGMENTATION_CASTERFACTORY_H
#define CLDEPLUS_SEGMENTATION_CASTERFACTORY_H

#include "Transformation/TypeCaster.h"

namespace CLDEPlus {
    namespace Segmentation {
        struct CasterFactory {
            static Transformation::SPtrCaster CreateByteCaster();
            static Transformation::SPtrCaster CreateBooleanCaster();
            static Transformation::SPtrCaster CreateDoubleCaster();
            static Transformation::SPtrCaster CreateFloatCaster();
            static Transformation::SPtrCaster CreateInt16Caster();
            static Transformation::SPtrCaster CreateInt32Caster();
            static Transformation::SPtrCaster CreateInt64Caster();
            static Transformation::SPtrCaster CreateUInt16Caster();
            static Transformation::SPtrCaster CreateUInt32Caster();
            static Transformation::SPtrCaster CreateUInt64Caster();
            static Transformation::SPtrCaster CreateStringCaster();
            static Transformation::SPtrCaster CreateVarCharCaster();
        };
    }
}


#endif //CLDEPLUS_SEGMENTATION_CASTERFACTORY_H
