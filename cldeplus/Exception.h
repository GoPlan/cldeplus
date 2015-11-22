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

#ifndef CLDEPLUS_EXCEPTION_H
#define CLDEPLUS_EXCEPTION_H

#include "CldePlus-Portable.h"

namespace CLDEPlus {
    class Exception : public exception {

        mutable string _message;
        string _name;

    public:
        explicit Exception(string const &message) : _message{message}, _name{"Exception"} { };
        explicit Exception(char const *message) : _message(message), _name{"Exception"} { };
        virtual ~Exception() = default;

        // Exception
        virtual const char *what() const noexcept override {

            string tmp{std::move(_message)};

            _message.reserve(Name().length() + tmp.length() + 3);
            _message += "[" + Name() + "]";
            _message += tmp;

            return _message.c_str();
        };

        // Locals
        virtual const string &Name() const noexcept { return _name; };
    };
}


#endif //CLDEPLUS_EXCEPTIONS_EXCEPTION_H
