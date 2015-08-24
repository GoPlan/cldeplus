//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H
#define CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H

#include "CLDEException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class CLDENotImplementedException : public CLDEException {

                static const std::string _name;

            public:
                CLDENotImplementedException(const char *message) : CLDEException(message) { };
                CLDENotImplementedException(const std::string &message) : CLDEException(message) { };
                CLDENotImplementedException(const CLDENotImplementedException &) = default;
                CLDENotImplementedException(CLDENotImplementedException &&) = default;
                CLDENotImplementedException &operator=(const CLDENotImplementedException &) = default;
                CLDENotImplementedException &operator=(CLDENotImplementedException &&) = default;
                virtual ~CLDENotImplementedException() = default;

                // CLDEException
                virtual const std::string &Name() const noexcept override { return _name; };
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H