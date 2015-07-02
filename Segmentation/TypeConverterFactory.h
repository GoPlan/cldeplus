//
// Created by LE, Duc Anh on 7/2/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_TYPECONVERTERFACTORY_H
#define CLOUD_E_PLUS_SEGMENTATION_TYPECONVERTERFACTORY_H

#include "Transformation/TypeConverter.h"

namespace Cloude {
    namespace Segmentation {

        class TypeConverterFactory {

        public:
            TypeConverterFactory() = delete;
            TypeConverterFactory(const TypeConverterFactory &) = delete;
            TypeConverterFactory(TypeConverterFactory &&) = delete;
            TypeConverterFactory &operator=(const TypeConverterFactory &) = delete;
            TypeConverterFactory &operator=(TypeConverterFactory &&) = delete;
            virtual ~TypeConverterFactory() = delete;

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


#endif //CLOUD_E_PLUS_SEGMENTATION_TRANSFORMATION_TYPECONVERTERFACTORY_H
