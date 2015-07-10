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

                static const std::string _name;

            public:
                cldeNonSupportedDataTypeException(const char *message) : cldeException(message) { };
                cldeNonSupportedDataTypeException(const std::string &message) : cldeException(message) { };
                cldeNonSupportedDataTypeException(const cldeNonSupportedDataTypeException &) = default;
                cldeNonSupportedDataTypeException(cldeNonSupportedDataTypeException &&) = default;
                cldeNonSupportedDataTypeException &operator=(const cldeNonSupportedDataTypeException &) = default;
                cldeNonSupportedDataTypeException &operator=(cldeNonSupportedDataTypeException &&) = default;
                ~cldeNonSupportedDataTypeException() = default;

                // cldeException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H
