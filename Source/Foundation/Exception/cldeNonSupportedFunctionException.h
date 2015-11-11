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

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDENonSupportedFunctionException : public CLDEException {

                static const string _name;

            public:
                explicit CLDENonSupportedFunctionException(char const *message) : CLDEException(message) { };
                explicit CLDENonSupportedFunctionException(string const &message) : CLDEException(message) { };
                CLDENonSupportedFunctionException(CLDENonSupportedFunctionException const &) = default;
                CLDENonSupportedFunctionException(CLDENonSupportedFunctionException &&) = default;
                CLDENonSupportedFunctionException &operator=(CLDENonSupportedFunctionException const &) = default;
                CLDENonSupportedFunctionException &operator=(CLDENonSupportedFunctionException &&) = default;
                virtual ~CLDENonSupportedFunctionException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override { return _name; };
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
