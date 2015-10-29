//
// Created by LE, Duc Anh on 8/26/15.
//

#ifndef CLDEPLUS_FOUNDATION_EXCEPTION_CLDEENTITYMAPEXCEPTION_H
#define CLDEPLUS_FOUNDATION_EXCEPTION_CLDEENTITYMAPEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDEEntityMapException : public CLDEException {

                static std::string _name;

            public:
                CLDEEntityMapException(std::string const &message) : CLDEException(message) { };
                CLDEEntityMapException(const CLDEEntityMapException &) = default;
                CLDEEntityMapException(CLDEEntityMapException &&) = default;
                CLDEEntityMapException &operator=(const CLDEEntityMapException &) = default;
                CLDEEntityMapException &operator=(CLDEEntityMapException &&) = default;
                virtual ~CLDEEntityMapException() = default;

                // CLDEException
                virtual const std::string &Name() const noexcept override { return _name; }
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_EXCEPTION_CLDEENTITYMAPEXCEPTION_H
