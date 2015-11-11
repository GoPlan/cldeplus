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

#ifndef CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVEHELPER_H
#define CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVEHELPER_H

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {

                struct PrimitiveHelper {
                    template<typename T>
                    static T ToPrimitive(SPtrValue const &value) {

                        if (!value->isNumeric() || value->getCategory() != ValueCategory::Numeric) {
                            string msg{"Value is not numeric"};
                            throw Exception::CLDENonSupportedDataTypeException{msg};
                        }

                        T const *ptrResult = reinterpret_cast<const T *>(value->PointerToBuffer());

                        return *ptrResult;
                    };
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVEHELPER_H
