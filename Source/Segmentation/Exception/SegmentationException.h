//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLDEPLUS_SEGMENTATION_EXCEPTION_SEGMENTATIONEXCEPTION_H
#define CLDEPLUS_SEGMENTATION_EXCEPTION_SEGMENTATIONEXCEPTION_H

#include "../../Foundation/Exception/CLDEException.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Exception {

            class SegmentationException : public Foundation::Exception::CLDEException {

                static const string _name;

            public:
                SegmentationException(const string &message) : CLDEException{message} { };
                SegmentationException(const SegmentationException &) = default;
                SegmentationException(SegmentationException &&) = default;
                SegmentationException &operator=(const SegmentationException &) = default;
                SegmentationException &operator=(SegmentationException &&) = default;
                virtual ~SegmentationException() = default;

                // CLDEException
                virtual const string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLDEPLUS_SEGMENTATION_EXCEPTION_SEGMENTATIONEXCEPTION_H
