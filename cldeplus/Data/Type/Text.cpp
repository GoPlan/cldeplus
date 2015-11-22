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

#include "Text.h"

namespace CLDEPlus {
    namespace Data {
        namespace Type {

            Text::Text(string const &text)
                    : Text(text.c_str()) {
                //
            }

            Text::Text(char const *text)
                    : CharacterValue{ValueType::Text, strlen(text) + 1},
                      _buffer{strdup(text)} {
                //
            }

            Text::Text(unsigned long length)
                    : CharacterValue{ValueType::Text, length},
                      _buffer{(char *) calloc(length, sizeof(char))} {
                //
            }

            Text::~Text() {
                if (_buffer != nullptr) free(_buffer);
            }

            void *Text::PointerToBuffer() {
                return _buffer;
            }

            size_t Text::getActualSize() {
                return strlen(_buffer) + 1;
            }

            string Text::CopyToString() const {
                return string{_buffer};
            }
        }
    }
}



