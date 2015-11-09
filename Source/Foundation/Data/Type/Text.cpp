//
// Created by LE, Duc Anh on 6/10/15.
//

#include "Text.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                Text::Text(string const &text)
                        : Text(text.c_str()) {
                    //
                }

                Text::Text(char const *text)
                        : CharacterValue{Data::ValueType::Text, strlen(text) + 1},
                          _buffer{strdup(text)} {
                    //
                }

                Text::Text(unsigned long length)
                        : CharacterValue{Data::ValueType::Text, length},
                          _buffer{(char *) calloc(length, sizeof(char))} {
                    //
                }

                Text::~Text() {
                    if (_buffer != nullptr) free(_buffer);
                }

                void *Text::PointerToBuffer() {
                    return _buffer;
                }

                size_t Text::getActualSize() {
                    return strlen(_buffer) + 1;
                }

                string Text::ToString() const {
                    return string{_buffer};
                }
            }
        }
    }
}



