//
// Created by LE, Duc Anh on 6/10/15.
//

#include "String.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                String::String(const std::string &string)
                        : _value(string), CharacterValue(ValueType::String, _value.length()) {
                    //
                }

                bool String::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const String &>(rhs);
                        return ((cast._value.compare(this->_value)) == 0);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                void *String::RawPointerToValueBuffer() {
                    std::string msg{"String type does not support non-const RawPointerToValueBuffer." \
                                                        "Use VarChar instead."};
                    throw Exception::cldeNonSupportedFunctionException{msg};
                }

                const std::string String::CopyToString() const {
                    return _value;
                }

                const std::string &String::ToString() const {
                    return _value;
                }

                const char *String::ToCString() const {
                    return _value.c_str();
                }
            }
        }
    }
}


