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

#include <cstdlib>
#include <cstring>
#include "VarChar.h"

namespace CLDEPlus {
    namespace Data {
        namespace Type {

            VarChar::VarChar(size_t length)
                    : CharacterValue(ValueType::VarChar, sizeof(char) * (length + 1)) {
                init();
            }

            VarChar::VarChar(string const &value)
                    : VarChar(value.c_str()) {
                //
            }

            VarChar::VarChar(char const *value)
                    : CharacterValue(ValueType::VarChar, sizeof(char) * (strlen(value) + 1)) {
                init(value);
            }

            VarChar::VarChar(VarChar const &varchar)
                    : CharacterValue(ValueType::VarChar, sizeof(char) * (strlen(varchar._value) + 1)),
                      _value{strdup(varchar._value)} {
                //
            }

            VarChar::VarChar(VarChar &&varchar)
                    : CharacterValue(ValueType::VarChar, sizeof(char) * (strlen(varchar._value) + 1)),
                      _value{varchar._value} {
                varchar._reservedSize = 0;
                varchar._value = nullptr;
            }

            VarChar &VarChar::operator=(VarChar const &varchar) {

                if (this == &varchar)
                    return *this;

                if (_value != nullptr && _value != NULL) {
                    memset(_value, 0x0, _reservedSize);
                    free(_value);
                    _value = nullptr;
                }

                _dataType = varchar._dataType;
                _reservedSize = varchar._reservedSize;
                _value = strdup(varchar._value);

                return *this;
            }

            VarChar &VarChar::operator=(VarChar &&varchar) {

                if (_value != nullptr && _value != NULL) {
                    memset(_value, 0x0, _reservedSize);
                    free(_value);
                    _value = nullptr;
                }

                _dataType = std::move(varchar._dataType);
                _reservedSize = std::move(varchar._reservedSize);
                _value = std::move(varchar._value);

                return *this;
            }

            VarChar::~VarChar() {
                if (_value != nullptr && _value != NULL) {
                    free(_value);
                }
            }

            string VarChar::CopyToString() const {
                return string(_value);
            }

            void *VarChar::PointerToBuffer() {
                return _value;
            }

            size_t VarChar::getActualSize() {
                return strlen(_value) + 1;
            }

            void VarChar::init() {
                _value = (char *) calloc(_reservedSize, sizeof(char));
            }

            void VarChar::init(char const *value) {
                _value = strdup(value);
            }
        }
    }
}


