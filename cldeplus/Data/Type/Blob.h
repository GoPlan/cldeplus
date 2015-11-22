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

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_BLOB_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_BLOB_H

#include "../Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Blob : public Value {

                    void *_buffer = nullptr;

                public:
                    Blob() = default;
                    Blob(const Blob &) = default;
                    Blob(Blob &&) = default;
                    Blob &operator=(const Blob &) = default;
                    Blob &operator=(Blob &&) = default;
                    ~Blob() = default;
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_BLOB_H
