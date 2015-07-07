//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class cldeEntityException : public cldeException {

            static const std::string _name;

            public:
                cldeEntityException(const char *message) : cldeException(message) { };
                cldeEntityException(const std::string &message) : cldeException(message) { };
                cldeEntityException(const cldeEntityException &) = default;
                cldeEntityException(cldeEntityException &&) = default;
                cldeEntityException &operator=(const cldeEntityException &) = default;
                cldeEntityException &operator=(cldeEntityException &&) = default;
                ~cldeEntityException() = default;

                // cldeException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H
