//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TONUMERIC_HPP
#define CLOUD_E_PLUS_FOUNDATION_DATA_TONUMERIC_HPP

#include "Value.h"
#include "../Exception/CLDENonSupportedDataTypeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            template<typename T>
            T NumericToPrimative(const SPtrValue &value) {

                if (!value->isNumeric() || value->getCategory() != ValueCategory::Numeric) {
                    std::string msg{"Value is not numeric"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }

                const T *ptrResult = reinterpret_cast<const T *>(value->PointerToBuffer());

                return *ptrResult;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TONUMERIC_HPP
