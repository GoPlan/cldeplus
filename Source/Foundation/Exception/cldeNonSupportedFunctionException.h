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

                static const string _name;

            public:
                explicit CLDENonSupportedFunctionException(char const *message) : CLDEException(message) { };
                explicit CLDENonSupportedFunctionException(string const &message) : CLDEException(message) { };
                CLDENonSupportedFunctionException(CLDENonSupportedFunctionException const &) = default;
                CLDENonSupportedFunctionException(CLDENonSupportedFunctionException &&) = default;
                CLDENonSupportedFunctionException &operator=(CLDENonSupportedFunctionException const &) = default;
                CLDENonSupportedFunctionException &operator=(CLDENonSupportedFunctionException &&) = default;
                virtual ~CLDENonSupportedFunctionException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override { return _name; };
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDENONSUPPORTEDFUNCTIONEXCEPTION_H
