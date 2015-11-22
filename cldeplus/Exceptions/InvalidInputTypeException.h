//
// Created by Duc-Anh LE on 11/22/15.
//

#ifndef CLDEPLUS_EXCEPTIONS_INVALIDINPUTTYPEEXCEPTION_H
#define CLDEPLUS_EXCEPTIONS_INVALIDINPUTTYPEEXCEPTION_H

#include "../Exception.h"

namespace CLDEPlus {
    namespace Exceptions {

        class InvalidInputTypeException : public Exception {

            static const string _name;

        public:
            explicit InvalidInputTypeException(char const *message) : Exception(message) { };
            explicit InvalidInputTypeException(string const &message) : Exception(message) { };
            virtual ~InvalidInputTypeException() = default;

            // CLDEException
            virtual string const &Name() const noexcept override { return _name; };
        };
    }
}



#endif //CLDEPLUS_EXCEPTIONS_INVALIDINPUTTYPEEXCEPTION_H
