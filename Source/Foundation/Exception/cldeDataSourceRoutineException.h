//
// Created by LE, Duc Anh on 5/26/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
#define CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H

#include "CLDEException.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Exception {

            class CLDEDataSourceRoutineException : public CLDEException {

                static string _name;

            public:
                explicit CLDEDataSourceRoutineException(char const *message) : CLDEException(message) { };
                explicit CLDEDataSourceRoutineException(string const &message) : CLDEException(message) { };
                CLDEDataSourceRoutineException(CLDEDataSourceRoutineException const &) = default;
                CLDEDataSourceRoutineException(CLDEDataSourceRoutineException &&) = default;
                CLDEDataSourceRoutineException &operator=(CLDEDataSourceRoutineException const &) = default;
                CLDEDataSourceRoutineException &operator=(CLDEDataSourceRoutineException &&) = default;
                ~CLDEDataSourceRoutineException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_EXCEPTION_CLDEDATASOURCEROUTINEEXCEPTION_H
