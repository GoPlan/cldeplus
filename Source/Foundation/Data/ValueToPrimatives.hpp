//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TONUMERIC_HPP
#define CLDEPLUS_FOUNDATION_DATA_TONUMERIC_HPP

#include "Value.h"
#include "../Exception/CLDENonSupportedDataTypeException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            template<typename T>
            T NumericToPrimative(const SPtrValue &value) {

                if (!value->isNumeric() || value->getCategory() != ValueCategory::Numeric) {
                    string msg{"Value is not numeric"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }

                const T *ptrResult = reinterpret_cast<const T *>(value->PointerToBuffer());

                return *ptrResult;
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_DATA_TONUMERIC_HPP
