//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class cldeNonSupportedFunctionException : public cldeException {

            public:
                cldeNonSupportedFunctionException(const char *message) : cldeException(message) { };
                cldeNonSupportedFunctionException(const std::string &message) : cldeException(message) { };
                ~cldeNonSupportedFunctionException() = default;
                cldeNonSupportedFunctionException(const cldeNonSupportedFunctionException &rhs) = default;
                cldeNonSupportedFunctionException &operator=(const cldeNonSupportedFunctionException &rhs) = default;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
