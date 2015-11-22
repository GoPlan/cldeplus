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

#ifndef CLDEPLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H
#define CLDEPLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H

#include "../../Foundation/Exception/CLDEException.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Exception {

            class TransformationException : public Foundation::Exception::CLDEException {

                static const string _name;

            public:
                TransformationException(const string &message) : CLDEException{message} { };
                TransformationException(const TransformationException &) = default;
                TransformationException(TransformationException &&) = default;
                TransformationException &operator=(const TransformationException &) = default;
                TransformationException &operator=(TransformationException &&) = default;
                virtual ~TransformationException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H
