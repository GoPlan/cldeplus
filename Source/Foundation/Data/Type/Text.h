/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H

#include "../../../Port/Definitions.h"
#include "../CharacterValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Text : public CharacterValue {

                    char *_buffer = nullptr;

                public:
                    explicit Text(string const &text);
                    explicit Text(char const *text);
                    explicit Text(unsigned long length);
                    Text(Text const &) = default;
                    Text(Text &&) = default;
                    Text &operator=(Text const &) = default;
                    Text &operator=(Text &&) = default;
                    ~Text();

                    // Value
                    virtual void *PointerToBuffer() override;
                    virtual size_t getActualSize() override;

                    // IPrintable
                    virtual string ToString() const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_TEXT_H
