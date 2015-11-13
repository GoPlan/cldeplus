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

#ifndef CLDEPLUS_FOUNDATION_COMMON_ICOMPARABLE_H
#define CLDEPLUS_FOUNDATION_COMMON_ICOMPARABLE_H

#include "../../Portable/CommonTypes.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {

            struct IEquatable : public std::binary_function<IEquatable, IEquatable, bool> {
                virtual bool Equal(IEquatable const &rhs) const = 0;
            };
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_COMMON_ICOMPARABLE_H
