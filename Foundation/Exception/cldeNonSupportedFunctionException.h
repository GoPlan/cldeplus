//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
#define CLOUD_E_CPLUS_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {
            class cldeNonSupportedFunctionException : public cldeException {
            public:
                cldeNonSupportedFunctionException(const char *message) : cldeException(message) { };
                virtual ~cldeNonSupportedFunctionException() = default;
                cldeNonSupportedFunctionException(const cldeNonSupportedFunctionException &rhs) = default;
                cldeNonSupportedFunctionException &operator=(const cldeNonSupportedFunctionException &rhs) = default;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
