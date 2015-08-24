//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H
#define CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H

#include <string>
#include "../../Foundation/Exception/CLDEException.h"

namespace Cloude {
    namespace Segmentation {
        namespace Exception {

            class TransformationException : public Foundation::Exception::CLDEException {

            static const std::string _name;

            public:
                TransformationException(const std::string &message) : CLDEException{message} { };
                TransformationException(const TransformationException &) = default;
                TransformationException(TransformationException &&) = default;
                TransformationException &operator=(const TransformationException &) = default;
                TransformationException &operator=(TransformationException &&) = default;
                virtual ~TransformationException() = default;

                // CLDEException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H
