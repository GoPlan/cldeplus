//
// Created by LE, Duc Anh on 7/2/15.
//

#include <Segmentation/Transformation/Caster/ByteCaster.h>
#include <Segmentation/Transformation/Caster/BooleanCaster.h>
#include <Segmentation/Transformation/Caster/DoubleCaster.h>
#include <Segmentation/Transformation/Caster/FloatCaster.h>
#include <Segmentation/Transformation/Caster/Int16Caster.h>
#include <Segmentation/Transformation/Caster/Int32Caster.h>
#include <Segmentation/Transformation/Caster/Int64Caster.h>
#include <Segmentation/Transformation/Caster/UInt16Caster.h>
#include <Segmentation/Transformation/Caster/UInt32Caster.h>
#include <Segmentation/Transformation/Caster/UInt64Caster.h>
#include <Segmentation/Transformation/Caster/StringCaster.h>
#include <Segmentation/Transformation/Caster/VarCharCaster.h>
#include "CasterFactory.h"

namespace Cloude {
    namespace Segmentation {

        Transformation::SPtrCaster CasterFactory::CreateByteConverter() {
            return std::make_shared<Transformation::Caster::ByteCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateBooleanConverter() {
            return std::make_shared<Transformation::Caster::BooleanCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateDoubleConverter() {
            return std::make_shared<Transformation::Caster::DoubleCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateFloatConverter() {
            return std::make_shared<Transformation::Caster::FloatCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateInt16Converter() {
            return std::make_shared<Transformation::Caster::Int16Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateInt32Converter() {
            return std::make_shared<Transformation::Caster::Int32Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateInt64Converter() {
            return std::make_shared<Transformation::Caster::Int64Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateUInt16Converter() {
            return std::make_shared<Transformation::Caster::UInt16Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateUInt32Converter() {
            return std::make_shared<Transformation::Caster::UInt32Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateUInt64Converter() {
            return std::make_shared<Transformation::Caster::UInt64Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateStringConverter() {
            return std::make_shared<Transformation::Caster::StringCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateVarCharConverter() {
            return std::make_shared<Transformation::Caster::VarCharCaster>();
        }
    }
}

