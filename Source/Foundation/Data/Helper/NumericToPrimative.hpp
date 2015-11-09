//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_HELPER_NUMERICTOPRIMITIVE_HPP
#define CLDEPLUS_FOUNDATION_DATA_HELPER_NUMERICTOPRIMITIVE_HPP

#include "../Value.h"
#include "../../Exception/cldeNonSupportedDataTypeException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {

                template<typename T>
                T NumericToPrimative(SPtrValue const &value) {

                    if (!value->isNumeric() || value->getCategory() != ValueCategory::Numeric) {
                        string msg{"Value is not numeric"};
                        throw Exception::CLDENonSupportedDataTypeException{msg};
                    }

                    T const *ptrResult = reinterpret_cast<const T *>(value->PointerToBuffer());

                    return *ptrResult;
                };
            }
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_DATA_HELPER_NUMERICTOPRIMITIVE_HPP
