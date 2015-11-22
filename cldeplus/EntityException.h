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

#ifndef CLDEPLUS_ENTITYEXCEPTION_H
#define CLDEPLUS_ENTITYEXCEPTION_H

#include "Exception.h"

namespace CLDEPlus {

    class EntityException : public Exception {

        static const string _name;

    public:
        explicit EntityException(char const *message) : Exception(message) { };
        explicit EntityException(string const &message) : Exception(message) { };
        ~EntityException() = default;

        // Exception
        virtual const string &Name() const noexcept override { return _name; };
    };
}


#endif //CLDEPLUS_ENTITYEXCEPTION_H
