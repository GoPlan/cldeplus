//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Text.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Text::Text(const std::string &text) : CharacterValue{Data::ValueType::Text, text.length()},
                                                      _value{text} {
                    //
                }

                Text::Text(unsigned long length) : CharacterValue{Data::ValueType::Text, length} {
                    _value.reserve(length);
                }

                Text::~Text() {
                    _value.clear();
                    _value.shrink_to_fit();
                }

                void *Text::RawPointerToValueBuffer() {
                    return &_value;
                }

                std::string Text::ToString() const {
                    return _value;
                }
            }
        }
    }
}



