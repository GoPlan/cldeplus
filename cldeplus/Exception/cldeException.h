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

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEEXCEPTION_H

#include "Portable.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDEException : public exception {

                mutable string _message;

            public:
                explicit CLDEException(string const &message) : _message{message} { };
                explicit CLDEException(char const *message) : _message(message) { };
                CLDEException(CLDEException const &) = default;
                CLDEException(CLDEException &&) = default;
                CLDEException &operator=(CLDEException const &) = default;
                CLDEException &operator=(CLDEException &&) = default;
                virtual ~CLDEException() = default;

                // Exception
                virtual const char *what() const noexcept override {

                    string tmp{std::move(_message)};

                    _message.reserve(Name().length() + tmp.length() + 3);
                    _message += "[" + Name() + "]";
                    _message += tmp;

                    return _message.c_str();
                };

                // Locals
                virtual const string &Name() const noexcept = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEEXCEPTION_H
