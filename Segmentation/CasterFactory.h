//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H
#define CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H

#include "Transformation/TypeCaster.h"

namespace Cloude {
    namespace Segmentation {

        class CasterFactory {

        public:
            CasterFactory() = delete;
            CasterFactory(const CasterFactory &) = delete;
            CasterFactory(CasterFactory &&) = delete;
            CasterFactory &operator=(const CasterFactory &) = delete;
            CasterFactory &operator=(CasterFactory &&) = delete;
            virtual ~CasterFactory() = delete;

            static Transformation::SPtrTypeConverter CreateByteConverter();
            static Transformation::SPtrTypeConverter CreateBooleanConverter();
            static Transformation::SPtrTypeConverter CreateDoubleConverter();
            static Transformation::SPtrTypeConverter CreateFloatConverter();
            static Transformation::SPtrTypeConverter CreateInt16Converter();
            static Transformation::SPtrTypeConverter CreateInt32Converter();
            static Transformation::SPtrTypeConverter CreateInt64Converter();
            static Transformation::SPtrTypeConverter CreateUInt16Converter();
            static Transformation::SPtrTypeConverter CreateUInt32Converter();
            static Transformation::SPtrTypeConverter CreateUInt64Converter();
            static Transformation::SPtrTypeConverter CreateStringConverter();
            static Transformation::SPtrTypeConverter CreateVarCharConverter();
        };
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_CASTERFACTORY_H
