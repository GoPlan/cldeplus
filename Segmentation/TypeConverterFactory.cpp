//
// Created by LE, Duc Anh on 7/2/15.
//

#include <Segmentation/Transformation/Converter/ByteConverter.h>
#include <Segmentation/Transformation/Converter/BooleanConverter.h>
#include <Segmentation/Transformation/Converter/DoubleConverter.h>
#include <Segmentation/Transformation/Converter/FloatConverter.h>
#include <Segmentation/Transformation/Converter/Int16Converter.h>
#include <Segmentation/Transformation/Converter/Int32Converter.h>
#include <Segmentation/Transformation/Converter/Int64Converter.h>
#include <Segmentation/Transformation/Converter/UInt16Converter.h>
#include <Segmentation/Transformation/Converter/UInt32Converter.h>
#include <Segmentation/Transformation/Converter/UInt64Converter.h>
#include <Segmentation/Transformation/Converter/StringConverter.h>
#include <Segmentation/Transformation/Converter/VarCharConverter.h>
#include "TypeConverterFactory.h"

namespace Cloude {
    namespace Segmentation {

        Transformation::SPtrTypeConverter TypeConverterFactory::CreateByteConverter() {
            return std::make_shared<Transformation::Converter::ByteConverter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateBooleanConverter() {
            return std::make_shared<Transformation::Converter::BooleanConverter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateDoubleConverter() {
            return std::make_shared<Transformation::Converter::DoubleConverter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateFloatConverter() {
            return std::make_shared<Transformation::Converter::FloatConverter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateInt16Converter() {
            return std::make_shared<Transformation::Converter::Int16Converter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateInt32Converter() {
            return std::make_shared<Transformation::Converter::Int32Converter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateInt64Converter() {
            return std::make_shared<Transformation::Converter::Int64Converter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateUInt16Converter() {
            return std::make_shared<Transformation::Converter::UInt16Converter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateUInt32Converter() {
            return std::make_shared<Transformation::Converter::UInt32Converter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateUInt64Converter() {
            return std::make_shared<Transformation::Converter::UInt64Converter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateStringConverter() {
            return std::make_shared<Transformation::Converter::StringConverter>();
        }
        Transformation::SPtrTypeConverter TypeConverterFactory::CreateVarCharConverter() {
            return std::make_shared<Transformation::Converter::VarCharConverter>();
        }
    }
}


