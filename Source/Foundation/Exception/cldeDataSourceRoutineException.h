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

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDEDataSourceRoutineException : public CLDEException {

                static string _name;

            public:
                explicit CLDEDataSourceRoutineException(char const *message) : CLDEException(message) { };
                explicit CLDEDataSourceRoutineException(string const &message) : CLDEException(message) { };
                CLDEDataSourceRoutineException(CLDEDataSourceRoutineException const &) = default;
                CLDEDataSourceRoutineException(CLDEDataSourceRoutineException &&) = default;
                CLDEDataSourceRoutineException &operator=(CLDEDataSourceRoutineException const &) = default;
                CLDEDataSourceRoutineException &operator=(CLDEDataSourceRoutineException &&) = default;
                ~CLDEDataSourceRoutineException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
