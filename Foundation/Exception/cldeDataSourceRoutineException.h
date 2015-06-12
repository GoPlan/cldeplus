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

            public:
                cldeDataSourceRoutineException(const char *message) : cldeException(message) { };
                cldeDataSourceRoutineException(const std::string &message) : cldeException(message) { };
                ~cldeDataSourceRoutineException() = default;
                cldeDataSourceRoutineException(const cldeDataSourceRoutineException &rhs) = default;
                cldeDataSourceRoutineException &operator=(const cldeDataSourceRoutineException &rhs) = default;

            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
