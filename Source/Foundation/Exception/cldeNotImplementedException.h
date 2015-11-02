//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLDEPLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H
#define CLDEPLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDENotImplementedException : public CLDEException {

                static const string _name;

            public:
                CLDENotImplementedException(const char *message) : CLDEException(message) { };
                CLDENotImplementedException(const string &message) : CLDEException(message) { };
                CLDENotImplementedException(const CLDENotImplementedException &) = default;
                CLDENotImplementedException(CLDENotImplementedException &&) = default;
                CLDENotImplementedException &operator=(const CLDENotImplementedException &) = default;
                CLDENotImplementedException &operator=(CLDENotImplementedException &&) = default;
                virtual ~CLDENotImplementedException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override { return _name; };
            };
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_EXCEPTION_CLDENOTIMPLEMENTEDEXCEPTION_H
