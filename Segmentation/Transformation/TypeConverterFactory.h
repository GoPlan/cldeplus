//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTERFACTORY_H
#define CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTERFACTORY_H

#include "TypeConverter.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {

            class TypeConverterFactory {

            public:
                TypeConverterFactory() = delete;
                TypeConverterFactory(const TypeConverterFactory &) = delete;
                TypeConverterFactory(TypeConverterFactory &&) = delete;
                TypeConverterFactory &operator=(const TypeConverterFactory &) = delete;
                TypeConverterFactory &operator=(TypeConverterFactory &&) = delete;
                virtual ~TypeConverterFactory() = delete;

                static SPtrTypeConverter CreateByteConverter();
                static SPtrTypeConverter CreateBooleanConverter();
                static SPtrTypeConverter CreateDoubleConverter();
                static SPtrTypeConverter CreateFloatConverter();
                static SPtrTypeConverter CreateInt16Converter();
                static SPtrTypeConverter CreateInt32Converter();
                static SPtrTypeConverter CreateInt64Converter();
                static SPtrTypeConverter CreateUInt16Converter();
                static SPtrTypeConverter CreateUInt32Converter();
                static SPtrTypeConverter CreateUInt64Converter();
                static SPtrTypeConverter CreateStringConverter();
                static SPtrTypeConverter CreateVarCharConverter();
            };
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTERFACTORY_H
