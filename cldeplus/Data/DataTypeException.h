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

#ifndef CLDEPLUS_DATA_DATATYPEEXCEPTION_H
#define CLDEPLUS_DATA_DATATYPEEXCEPTION_H

#include "../Exception.h"

namespace CLDEPlus {
    namespace Data {

        class DataTypeException : public Exception {

            static string const _name;

        public:
            explicit DataTypeException(char const *message) : Exception(message) { };
            explicit DataTypeException(string const &message) : Exception(message) {};
            virtual ~DataTypeException() = default;

            // CLDEException
            virtual const string &Name() const noexcept override;
        };
    }
}

#endif //CLDEPLUS_DATA_DATATYPEEXCEPTION_H
