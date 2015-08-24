//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class cldeDataSourceRoutineException : public cldeException {

                static std::string _name;

            public:
                cldeDataSourceRoutineException(const char *message) : cldeException(message) { };
                cldeDataSourceRoutineException(const std::string &message) : cldeException(message) { };
                cldeDataSourceRoutineException(const cldeDataSourceRoutineException &) = default;
                cldeDataSourceRoutineException(cldeDataSourceRoutineException &&) = default;
                cldeDataSourceRoutineException &operator=(const cldeDataSourceRoutineException &) = default;
                cldeDataSourceRoutineException &operator=(cldeDataSourceRoutineException &&) = default;
                ~cldeDataSourceRoutineException() = default;

                // cldeException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
