//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H
#define CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H

#include "Transformation/TypeCaster.h"

namespace Cloude {
    namespace Segmentation {

        class CasterFactory {

            CasterFactory() = delete;
            CasterFactory(const CasterFactory &) = delete;
            CasterFactory(CasterFactory &&) = delete;
            CasterFactory &operator=(const CasterFactory &) = delete;
            CasterFactory &operator=(CasterFactory &&) = delete;
            virtual ~CasterFactory() = delete;

        public:
            static Transformation::SPtrCaster CreateByteConverter();
            static Transformation::SPtrCaster CreateBooleanConverter();
            static Transformation::SPtrCaster CreateDoubleConverter();
            static Transformation::SPtrCaster CreateFloatConverter();
            static Transformation::SPtrCaster CreateInt16Converter();
            static Transformation::SPtrCaster CreateInt32Converter();
            static Transformation::SPtrCaster CreateInt64Converter();
            static Transformation::SPtrCaster CreateUInt16Converter();
            static Transformation::SPtrCaster CreateUInt32Converter();
            static Transformation::SPtrCaster CreateUInt64Converter();
            static Transformation::SPtrCaster CreateStringConverter();
            static Transformation::SPtrCaster CreateVarCharConverter();
        };
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H
