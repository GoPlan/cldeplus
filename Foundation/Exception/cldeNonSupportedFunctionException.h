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

                static const std::string _name;

            public:
                cldeNonSupportedFunctionException(const char *message) : cldeException(message) { };
                cldeNonSupportedFunctionException(const std::string &message) : cldeException(message) { };
                ~cldeNonSupportedFunctionException() = default;
                cldeNonSupportedFunctionException(const cldeNonSupportedFunctionException &rhs) = default;
                cldeNonSupportedFunctionException &operator=(const cldeNonSupportedFunctionException &rhs) = default;

                // cldeException
                virtual const std::string &Name() const noexcept override { return _name; };
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
