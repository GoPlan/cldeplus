//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H
#define CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H

#include <Foundation/Exception/cldeException.h>

namespace Cloude {
    namespace Segmentation {
        namespace Exception {

            class TransformationException : public Foundation::Exception::cldeException {

            public:
                TransformationException(const std::string &message) : cldeException{message} { };
                TransformationException(const TransformationException &) = default;
                TransformationException(TransformationException &&) = default;
                TransformationException &operator=(const TransformationException &) = default;
                TransformationException &operator=(TransformationException &&) = default;
                virtual ~TransformationException() = default;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_TRANSFORMATIONEXCEPTION_H
