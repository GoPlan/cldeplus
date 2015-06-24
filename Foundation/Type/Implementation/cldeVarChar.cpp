//
// Created by LE, Duc Anh on 6/10/15.
//

#include <cstdlib>
#include <cstring>
#include "cldeVarChar.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeVarChar::cldeVarChar(size_t length)
                        : cldeCharacterValue(cldeValueType::VarChar, sizeof(char) * (length + 1)) {
                    init();
                }

                cldeVarChar::cldeVarChar(const std::string &value)
                        : cldeVarChar(value.c_str()) {
                    //
                }

                cldeVarChar::cldeVarChar(const char *value)
                        : cldeCharacterValue(cldeValueType::VarChar, sizeof(char) * (strlen(value) + 1)) {
                    init(value);
                }

                cldeVarChar::cldeVarChar(const cldeVarChar &varchar)
                        : cldeCharacterValue(cldeValueType::VarChar, sizeof(char) * (strlen(varchar._value) + 1)),
                          _value{strdup(varchar._value)} {
                    //
                }

                cldeVarChar::cldeVarChar(cldeVarChar &&varchar)
                        : cldeCharacterValue(cldeValueType::VarChar, sizeof(char) * (strlen(varchar._value) + 1)),
                          _value{varchar._value} {
                    varchar._length = 0;
                    varchar._value = nullptr;
                }

                cldeVarChar &cldeVarChar::operator=(const cldeVarChar &varchar) {

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

                cldeVarChar &cldeVarChar::operator=(cldeVarChar &&varchar) {

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

                cldeVarChar::~cldeVarChar() {
                    if (_value != nullptr && _value != NULL) {
                        free(_value);
                    }
                }

                bool cldeVarChar::Equal(const Common::IEquatable &rhs) const {
                    return false;
                }

                const std::string cldeVarChar::CopyToString() const {
                    return std::string(_value);
                }

                const std::string &cldeVarChar::ToString() const {
                    std::string msg{"VarChar does not support ToString. Use CopyToString(), ToCString() instead."};
                    throw Exception::cldeNonSupportedFunctionException{msg};
                }

                const char *cldeVarChar::ToCString() const {
                    return _value;
                }

                void *cldeVarChar::RawPointerToValueBuffer() {
                    return _value;
                }

                void cldeVarChar::init() {
                    _value = (char *) calloc(_length, sizeof(char));
                }

                void cldeVarChar::init(const char *value) {
                    _value = strdup(value);
                }
            }
        }
    }
}


