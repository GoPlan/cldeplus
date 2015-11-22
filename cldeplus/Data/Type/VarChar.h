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

#ifndef CLDEPLUS_DATA_TYPE_VARCHAR_H
#define CLDEPLUS_DATA_TYPE_VARCHAR_H

#include "../CharacterValue.h"

namespace CLDEPlus {
    namespace Data {
        namespace Type {

            class VarChar : public Data::CharacterValue {

                char *_value = nullptr;

                void init();
                void init(const char *value);

            public:
                explicit VarChar(size_t length);
                explicit VarChar(string const &value);
                explicit VarChar(char const *value);
                VarChar(VarChar const &);
                VarChar(VarChar &&);
                VarChar &operator=(VarChar const &);
                VarChar &operator=(VarChar &&);
                ~VarChar();

                // Value
                virtual void *PointerToBuffer() override;
                virtual size_t getActualSize() override;

                // IPrintable
                virtual string CopyToString() const override;
            };
        }
    }
}


#endif //CLDEPLUS_DATA_TYPE_VARCHAR_H
