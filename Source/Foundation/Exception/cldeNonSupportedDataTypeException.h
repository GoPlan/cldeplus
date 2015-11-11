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

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDENonSupportedDataTypeException : public CLDEException {

                static const string _name;

            public:
                explicit CLDENonSupportedDataTypeException(char const *message) : CLDEException(message) { };
                explicit CLDENonSupportedDataTypeException(string const &message) : CLDEException(message) { };
                CLDENonSupportedDataTypeException(CLDENonSupportedDataTypeException const &) = default;
                CLDENonSupportedDataTypeException(CLDENonSupportedDataTypeException &&) = default;
                CLDENonSupportedDataTypeException &operator=(CLDENonSupportedDataTypeException const &) = default;
                CLDENonSupportedDataTypeException &operator=(CLDENonSupportedDataTypeException &&) = default;
                virtual ~CLDENonSupportedDataTypeException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H
