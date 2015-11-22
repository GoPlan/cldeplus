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

#include "TypeCaster.h"
#include "../../Foundation/Data/Helper/ValueEnumsHelper.h"
#include "../Exception/TransformationException.h"

namespace CLDEPlus {
    namespace Segmentation {

        Foundation::Data::SPtrValue Transformation::TypeCaster::Cast(
                Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value) const {

            if (dataType == value->getDataType()) {
                return value;
            }

            switch (value->getDataType()) {
                case Foundation::Data::ValueType::Boolean:
                    break;
                case Foundation::Data::ValueType::Byte:
                    break;
                case Foundation::Data::ValueType::Int16:
                    break;
                case Foundation::Data::ValueType::Int32:
                    break;
                case Foundation::Data::ValueType::Int64:
                    break;
                case Foundation::Data::ValueType::UInt16:
                    break;
                case Foundation::Data::ValueType::UInt32:
                    break;
                case Foundation::Data::ValueType::UInt64:
                    break;
                case Foundation::Data::ValueType::Double:
                    break;
                case Foundation::Data::ValueType::Float:
                    break;
                case Foundation::Data::ValueType::String:
                    break;
                case Foundation::Data::ValueType::VarChar:
                    break;
                default: {
                    string type{Foundation::Data::Helper::ValueEnumsHelper::CopyValueTypeToString(value->getDataType())};
                    string msg{type + " converting is not supported"};
                    throw Segmentation::Exception::TransformationException{msg};
                }
            }

            return value;
        }
    }
}
