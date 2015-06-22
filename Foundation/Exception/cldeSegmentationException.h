//
// Created by LE, Duc Anh on 6/22/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDESEGMENTATIONEXCEPTION_H
#define CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDESEGMENTATIONEXCEPTION_H

#include "cldeException.h"

namespace Cloude {
    namespace Foundation {
        namespace Exception {
            class cldeSegmentationException : public cldeException {
            public:
                cldeSegmentationException(const std::string &message) : cldeException{message} { };
                cldeSegmentationException(const cldeSegmentationException &) = default;
                cldeSegmentationException(cldeSegmentationException &&) = default;
                cldeSegmentationException &operator=(const cldeSegmentationException &) = default;
                cldeSegmentationException &operator=(cldeSegmentationException &&) = default;
                virtual ~cldeSegmentationException() = default;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_EXCEPTION_CLDESEGMENTATIONEXCEPTION_H
