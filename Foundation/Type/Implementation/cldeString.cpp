//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeString.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                cldeString::cldeString(const std::string &string)
                        : _value(string), cldeCharacterValue(cldeValueType::String, _value.length()) {
                    //
                }

                bool cldeString::Equal(const Common::IEquatable &rhs) const {
                    try {
                        auto cast = dynamic_cast<const cldeString &>(rhs);
                        return ((cast._value.compare(this->_value)) == 0);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                void *cldeString::RawPointerToValueBuffer() {
                    std::string msg{"String type does not support non-const RawPointerToValueBuffer." \
                                                        "Use VarChar instead."};
                    throw Exception::cldeNonSupportedFunctionException{msg};
                }

                const std::string cldeString::CopyToString() const {
                    return _value;
                }

                const std::string &cldeString::ToString() const {
                    return _value;
                }

                const char *cldeString::ToCString() const {
                    return _value.c_str();
                }
            }
        }
    }
}


