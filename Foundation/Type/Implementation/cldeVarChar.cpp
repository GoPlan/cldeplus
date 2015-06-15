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

                cldeVarchar::cldeVarchar(size_t length) : cldeCharacterValue(cldeValueType::Varchar,
                                                                             sizeof(char) * (length + 1)) {
                    init();
                }

                cldeVarchar::cldeVarchar(const char *value) : cldeCharacterValue(cldeValueType::Varchar,
                                                                                 sizeof(char) * (strlen(value) + 1)) {
                    init(value);
                }

                cldeVarchar::~cldeVarchar() {
                    if (_value != nullptr && _value != NULL) {
                        free(_value);
                    }
                }

                bool cldeVarchar::Equal(const Common::IEquatable &rhs) {
                    return false;
                }

                const std::string cldeVarchar::CopyToString() const {
                    return std::string(_value);
                }

                const std::string &cldeVarchar::ToString() const {
                    const char *msg = "Varchar does not support ToString." \
                                        "Use ToStringCopy(), ToCString() instead.";
                    throw Exception::cldeNonSupportedFunctionException(msg);
                }

                const char *cldeVarchar::ToCString() const {
                    return _value;
                }

                void *cldeVarchar::RawPointerToValueBuffer() {
                    return _value;
                }

                void cldeVarchar::init() {
                    _value = (char *) calloc(_length, sizeof(char));
                }

                void cldeVarchar::init(const char *value) {
                    _value = strdup(value);
                }
            }
        }
    }
}


