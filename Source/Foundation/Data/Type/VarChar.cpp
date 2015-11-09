//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include <cstring>
#include "VarChar.h"

namespace CLDEPlus {
    namespace Foundation {
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

                string VarChar::ToString() const {
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
}


