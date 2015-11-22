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

#include "CasterFactory.h"
#include "Transformation/Caster/ByteCaster.h"
#include "Transformation/Caster/BooleanCaster.h"
#include "Transformation/Caster/DoubleCaster.h"
#include "Transformation/Caster/FloatCaster.h"
#include "Transformation/Caster/Int16Caster.h"
#include "Transformation/Caster/Int32Caster.h"
#include "Transformation/Caster/Int64Caster.h"
#include "Transformation/Caster/UInt16Caster.h"
#include "Transformation/Caster/UInt32Caster.h"
#include "Transformation/Caster/UInt64Caster.h"
#include "Transformation/Caster/StringCaster.h"
#include "Transformation/Caster/VarCharCaster.h"

namespace CLDEPlus {
    namespace Segmentation {

        Transformation::SPtrCaster CasterFactory::CreateByteCaster() {
            return cldeplus_make_shared<Transformation::Caster::ByteCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateBooleanCaster() {
            return cldeplus_make_shared<Transformation::Caster::BooleanCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateDoubleCaster() {
            return cldeplus_make_shared<Transformation::Caster::DoubleCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateFloatCaster() {
            return cldeplus_make_shared<Transformation::Caster::FloatCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateInt16Caster() {
            return cldeplus_make_shared<Transformation::Caster::Int16Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateInt32Caster() {
            return cldeplus_make_shared<Transformation::Caster::Int32Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateInt64Caster() {
            return cldeplus_make_shared<Transformation::Caster::Int64Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateUInt16Caster() {
            return cldeplus_make_shared<Transformation::Caster::UInt16Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateUInt32Caster() {
            return cldeplus_make_shared<Transformation::Caster::UInt32Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateUInt64Caster() {
            return cldeplus_make_shared<Transformation::Caster::UInt64Caster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateStringCaster() {
            return cldeplus_make_shared<Transformation::Caster::StringCaster>();
        }
        Transformation::SPtrCaster CasterFactory::CreateVarCharCaster() {
            return cldeplus_make_shared<Transformation::Caster::VarCharCaster>();
        }
    }
}


