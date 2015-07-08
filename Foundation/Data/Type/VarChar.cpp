//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include <cstring>
#include "VarChar.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                VarChar::VarChar(size_t length)
                        : CharacterValue(ValueType::VarChar, sizeof(char) * (length + 1)) {
                    init();
                }

                VarChar::VarChar(const std::string &value)
                        : VarChar(value.c_str()) {
                    //
                }

                VarChar::VarChar(const char *value)
                        : CharacterValue(ValueType::VarChar, sizeof(char) * (strlen(value) + 1)) {
                    init(value);
                }

                VarChar::VarChar(const VarChar &varchar)
                        : CharacterValue(ValueType::VarChar, sizeof(char) * (strlen(varchar._value) + 1)),
                          _value{strdup(varchar._value)} {
                    //
                }

                VarChar::VarChar(VarChar &&varchar)
                        : CharacterValue(ValueType::VarChar, sizeof(char) * (strlen(varchar._value) + 1)),
                          _value{varchar._value} {
                    varchar._length = 0;
                    varchar._value = nullptr;
                }

                VarChar &VarChar::operator=(const VarChar &varchar) {

                    if (this == &varchar)
                        return *this;

                    if (_value != nullptr && _value != NULL) {
                        memset(_value, 0x0, _length);
                        free(_value);
                        _value = nullptr;
                    }

                    _dataType = varchar._dataType;
                    _length = varchar._length;
                    _value = strdup(varchar._value);

                    return *this;
                }

                VarChar &VarChar::operator=(VarChar &&varchar) {

                    if (_value != nullptr && _value != NULL) {
                        memset(_value, 0x0, _length);
                        free(_value);
                        _value = nullptr;
                    }

                    _dataType = std::move(varchar._dataType);
                    _length = std::move(varchar._length);
                    _value = std::move(varchar._value);

                    return *this;
                }

                VarChar::~VarChar() {
                    if (_value != nullptr && _value != NULL) {
                        free(_value);
                    }
                }

                bool VarChar::Equal(const Common::IEquatable &rhs) const {
                    return false;
                }

                std::string VarChar::ToString() const {
                    return std::string(_value);
                }

                void *VarChar::RawPointerToValueBuffer() {
                    return _value;
                }

                void VarChar::init() {
                    _value = (char *) calloc(_length, sizeof(char));
                }

                void VarChar::init(const char *value) {
                    _value = strdup(value);
                }
            }
        }
    }
}


