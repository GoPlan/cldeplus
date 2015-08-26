//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H
#define CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H

#include "Transformation/TypeCaster.h"

namespace Cloude {
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


#endif //CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H
