//
// Created by LE, Duc Anh on 7/9/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TONUMERIC_HPP
#define CLOUD_E_PLUS_FOUNDATION_DATA_TONUMERIC_HPP

#include <stdexcept>
#include <Foundation/Exception/cldeNonSupportedDataTypeException.h>
#include "Value.h"


namespace Cloude {
    namespace Foundation {
        namespace Data {

            template<typename T>
            T ToNumeric(const SPtrValue &value) {

                if (!value->isNumeric() || value->getCategory() != ValueCategory::Numeric) {
                    std::string msg{"Value is not numeric"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }

                const T *ptrResult = reinterpret_cast<const T *>(value->RawPointerToValueBuffer());

                return *ptrResult;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TONUMERIC_HPP
