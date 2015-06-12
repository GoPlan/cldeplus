//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {
            class cldeNonSupportedDataTypeException : public cldeException {
            public:
                cldeNonSupportedDataTypeException(const char *message) : cldeException(message) { };
                cldeNonSupportedDataTypeException(const std::string &message) : cldeException(message) { };
                ~cldeNonSupportedDataTypeException() = default;
                cldeNonSupportedDataTypeException(const cldeNonSupportedDataTypeException &rhs) = default;
                cldeNonSupportedDataTypeException &operator=(const cldeNonSupportedDataTypeException &rhs) = default;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H
