//
// Created by LE, Duc Anh on 5/27/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDEEntityException : public CLDEException {

                static const string _name;

            public:
                CLDEEntityException(const char *message) : CLDEException(message) { };
                CLDEEntityException(const string &message) : CLDEException(message) { };
                CLDEEntityException(const CLDEEntityException &) = default;
                CLDEEntityException(CLDEEntityException &&) = default;
                CLDEEntityException &operator=(const CLDEEntityException &) = default;
                CLDEEntityException &operator=(CLDEEntityException &&) = default;
                virtual ~CLDEEntityException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEENTITYEXCEPTION_H
