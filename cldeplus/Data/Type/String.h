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

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H

#include "Portable.h"
#include "../CharacterValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class String : public CharacterValue {

                    string _value;

                public:
                    explicit String(string const &string);
                    explicit String(unsigned long size);
                    String() = default;
                    String(String const &) = default;
                    String(String &&) = default;
                    String &operator=(String const &) = default;
                    String &operator=(String &&) = default;
                    ~String() = default;

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


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_STRING_H
