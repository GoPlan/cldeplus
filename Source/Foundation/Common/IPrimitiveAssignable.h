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

#ifndef CLDEPLUS_FOUNDATION_COMMON_IPRIMITIVEASSIGNABLE_H
#define CLDEPLUS_FOUNDATION_COMMON_IPRIMITIVEASSIGNABLE_H

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {

            template<class T>
            struct IPrimitiveAssignable {
                virtual T &operator=(bool value) = 0;
                virtual T &operator=(double value) = 0;
                virtual T &operator=(float value) = 0;
                virtual T &operator=(int16 value) = 0;
                virtual T &operator=(int32 value) = 0;
                virtual T &operator=(int64 value) = 0;
                virtual T &operator=(uint16 value) = 0;
                virtual T &operator=(uint32 value) = 0;
                virtual T &operator=(uint64 value) = 0;
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_COMMON_IPRIMITIVEASSIGNABLE_H
