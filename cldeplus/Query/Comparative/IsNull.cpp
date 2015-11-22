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

#include "IsNull.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {
            namespace Comparative {

                ComparativeType IsNull::_type = ComparativeType::IsNull;

                const ComparativeType &IsNull::getComparativeType() const {
                    return _type;
                }

                const SPtrColumn &IsNull::getColumn() const {
                    return _column;
                }

                const bool IsNull::isComposite() const {
                    return false;
                }

                const Data::SPtrValue &IsNull::getValue() const {
                    const char *msg = "IsNull comparator does not support getValue() method.";
                    throw Exception::CLDENonSupportedFunctionException(msg);
                }
            }
        }
    }
}


