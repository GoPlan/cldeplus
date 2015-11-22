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

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEENUMS_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEENUMS_H

#include "../../Portable/CommonTypes.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            enum class ValueCategory {
                Numeric,
                DateTime,
                CharacterBased,
                Mathematic,
                UserDefined
            };

            enum class ValueType {
                Boolean,
                Byte,
                Blob,
                Int16,
                Int32,
                Int64,
                UInt16,
                UInt32,
                UInt64,
                Double,
                Float,
                String,
                VarChar,
                Text,
                Currency,
                DateTime,
                Date,
                Time,
                Point,
                Matrix
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEENUMS_H
