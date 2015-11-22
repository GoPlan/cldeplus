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

#ifndef CLDEPLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H
#define CLDEPLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H

#include "Portable.h"
#include "../ValueEnums.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {
                struct ValueEnumsHelper {
                    static string CopyCategoryToString(const ValueCategory &category);
                    static string CopyValueTypeToString(const ValueType &type);
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_HELPER_TYPEHELPER_H
