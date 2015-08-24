//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H

#include "CLDEException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {

            class CLDEDataSourceRoutineException : public CLDEException {

                static std::string _name;

            public:
                CLDEDataSourceRoutineException(const char *message) : CLDEException(message) { };
                CLDEDataSourceRoutineException(const std::string &message) : CLDEException(message) { };
                CLDEDataSourceRoutineException(const CLDEDataSourceRoutineException &) = default;
                CLDEDataSourceRoutineException(CLDEDataSourceRoutineException &&) = default;
                CLDEDataSourceRoutineException &operator=(const CLDEDataSourceRoutineException &) = default;
                CLDEDataSourceRoutineException &operator=(CLDEDataSourceRoutineException &&) = default;
                ~CLDEDataSourceRoutineException() = default;

                // CLDEException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
