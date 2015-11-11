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

#ifndef CLDEPLUS_FOUNDATION_EXCEPTION_CLDEENTITYMAPEXCEPTION_H
#define CLDEPLUS_FOUNDATION_EXCEPTION_CLDEENTITYMAPEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDEEntityMapException : public CLDEException {

                static string _name;

            public:
                explicit CLDEEntityMapException(string const &message) : CLDEException(message) { };
                CLDEEntityMapException(CLDEEntityMapException const &) = default;
                CLDEEntityMapException(CLDEEntityMapException &&) = default;
                CLDEEntityMapException &operator=(CLDEEntityMapException const &) = default;
                CLDEEntityMapException &operator=(CLDEEntityMapException &&) = default;
                virtual ~CLDEEntityMapException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override { return _name; }
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_EXCEPTION_CLDEENTITYMAPEXCEPTION_H
