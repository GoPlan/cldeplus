//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Text.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Text::Text(unsigned long length) : CharacterValue{Data::ValueType::Text, length} {
                    _buffer = (char *) calloc(_length, sizeof(char));
                }

                Text::~Text() {
                    if (_buffer != nullptr) free(_buffer);
                }

                void *Text::RawPointerToValueBuffer() {
                    return _buffer;
                }

                std::string Text::ToString() const {
                    return std::string{_buffer};
                }
            }
        }
    }
}



