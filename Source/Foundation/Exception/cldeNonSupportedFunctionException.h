//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDENonSupportedFunctionException : public CLDEException {

                static const std::string _name;

            public:
                CLDENonSupportedFunctionException(const char *message) : CLDEException(message) { };
                CLDENonSupportedFunctionException(const std::string &message) : CLDEException(message) { };
                CLDENonSupportedFunctionException(const CLDENonSupportedFunctionException &) = default;
                CLDENonSupportedFunctionException(CLDENonSupportedFunctionException &&) = default;
                CLDENonSupportedFunctionException &operator=(const CLDENonSupportedFunctionException &) = default;
                CLDENonSupportedFunctionException &operator=(CLDENonSupportedFunctionException &&) = default;
                virtual ~CLDENonSupportedFunctionException() = default;

                // CLDEException
                virtual const std::string &Name() const noexcept override { return _name; };
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
