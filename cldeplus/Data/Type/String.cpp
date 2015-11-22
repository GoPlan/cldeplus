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

#include "String.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                String::String(string const &string)
                        : _value(string), CharacterValue(ValueType::String, string.length() + 1) {
                    //
                }

                String::String(unsigned long size)
                        : CharacterValue{ValueType::String, size} {
                    _value.reserve(size);
                }

                void *String::PointerToBuffer() {
                    return &_value;
                }

                size_t String::getActualSize() {
                    return _value.length() + 1;
                }

                string String::ToString() const {
                    return _value;
                }
            }
        }
    }
}


