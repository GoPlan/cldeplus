//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H

#include "CLDEException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class CLDENonSupportedDataTypeException : public CLDEException {

                static const std::string _name;

            public:
                CLDENonSupportedDataTypeException(const char *message) : CLDEException(message) { };
                CLDENonSupportedDataTypeException(const std::string &message) : CLDEException(message) { };
                CLDENonSupportedDataTypeException(const CLDENonSupportedDataTypeException &) = default;
                CLDENonSupportedDataTypeException(CLDENonSupportedDataTypeException &&) = default;
                CLDENonSupportedDataTypeException &operator=(const CLDENonSupportedDataTypeException &) = default;
                CLDENonSupportedDataTypeException &operator=(CLDENonSupportedDataTypeException &&) = default;
                virtual ~CLDENonSupportedDataTypeException() = default;

                // CLDEException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDDATATYPEEXCEPTION_H