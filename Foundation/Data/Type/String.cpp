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


                String::String(unsigned long length)
                        : CharacterValue{ValueType::String, length} {
                    _value.reserve(length);
                }

                void *String::RawPointerToValueBuffer() {
                    return &_value;
                }

                std::string String::ToString() const {
                    return _value;
                }
            }
        }
    }
}


