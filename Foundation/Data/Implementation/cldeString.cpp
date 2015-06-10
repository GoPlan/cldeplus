//
// Created by LE, Duc Anh on 6/10/15.
//

#include "cldeString.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {

                cldeString::cldeString(const char *string) : _value(string),
                                                             cldeCharacterValue(cldeValueType::Varchar,
                                                                                _value.length()) {
                    //
                }

                bool cldeString::Equal(const Common::IEquatable &rhs) {
                    try {
                        auto cast = dynamic_cast<const cldeString &>(rhs);
                        return ((cast._value.compare(this->_value)) == 0);
                    } catch (std::bad_cast &ex) {
                        return false;
                    }
                }

                const void *cldeString::RawPointerToValueBuffer() {
                    return _value.c_str();
                }

                const std::string cldeString::CopyToString() const {
                    return _value;
                }

                const std::string &cldeString::ToString() const {
                    return _value;
                }

                void cldeString::SetValueToString(const char *value) {
                    _value.assign(value);
                }
            }
        }
    }
}


