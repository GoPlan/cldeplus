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

#ifndef CLDEPLUS_RELATION_EXCEPTION_NAMEDENTITYSTOREEXCEPTION_H
#define CLDEPLUS_RELATION_EXCEPTION_NAMEDENTITYSTOREEXCEPTION_H

#include "../../Foundation/Exception/CLDEException.h"

namespace CLDEPlus {
    namespace Relation {
        namespace Exception {

            class NamedEntityStoreException : Foundation::Exception::CLDEException {

                static string _name;

            public:
                NamedEntityStoreException(string const &message) : Foundation::Exception::CLDEException{message} { };
                NamedEntityStoreException(NamedEntityStoreException const &) = default;
                NamedEntityStoreException(NamedEntityStoreException &&) = default;
                NamedEntityStoreException &operator=(NamedEntityStoreException const &) = default;
                NamedEntityStoreException &operator=(NamedEntityStoreException &&) = default;
                virtual ~NamedEntityStoreException() = default;


            private:
                virtual const string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLDEPLUS_RELATION_EXCEPTION_NAMEDENTITYSTOREEXCEPTION_H
