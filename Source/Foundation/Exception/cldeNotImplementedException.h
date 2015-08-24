//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H
#define CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class cldeNotImplementedException : public cldeException {

                static const std::string _name;

            public:
                cldeNotImplementedException(const char *message) : cldeException(message) { };
                cldeNotImplementedException(const std::string &message) : cldeException(message) { };
                cldeNotImplementedException(const cldeNotImplementedException &) = default;
                cldeNotImplementedException(cldeNotImplementedException &&) = default;
                cldeNotImplementedException &operator=(const cldeNotImplementedException &) = default;
                cldeNotImplementedException &operator=(cldeNotImplementedException &&) = default;
                virtual ~cldeNotImplementedException() = default;

                // cldeException
                virtual const std::string &Name() const noexcept override { return _name; };
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H
