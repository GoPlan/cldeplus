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

#ifndef CLDEPLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H
#define CLDEPLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H

#include "cldeException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDENotImplementedException : public CLDEException {

                static const string _name;

            public:
                explicit CLDENotImplementedException(char const *message) : CLDEException(message) { };
                explicit CLDENotImplementedException(string const &message) : CLDEException(message) { };
                CLDENotImplementedException(CLDENotImplementedException const &) = default;
                CLDENotImplementedException(CLDENotImplementedException &&) = default;
                CLDENotImplementedException &operator=(CLDENotImplementedException const &) = default;
                CLDENotImplementedException &operator=(CLDENotImplementedException &&) = default;
                virtual ~CLDENotImplementedException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override { return _name; };
            };
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H