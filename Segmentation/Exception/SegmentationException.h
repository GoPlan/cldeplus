//
// Created by LE, Duc Anh on 7/1/15.
//

#ifndef CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_SEGMENTATIONEXCEPTION_H
#define CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_SEGMENTATIONEXCEPTION_H

#include <Foundation/Exception/cldeException.h>

namespace Cloude {
    namespace Segmentation {
        namespace Exception {

            class SegmentationException : public Foundation::Exception::cldeException {

            static const std::string _name;

            public:
                SegmentationException(const std::string &message) : cldeException{message} { };
                SegmentationException(const SegmentationException &) = default;
                SegmentationException(SegmentationException &&) = default;
                SegmentationException &operator=(const SegmentationException &) = default;
                SegmentationException &operator=(SegmentationException &&) = default;
                virtual ~SegmentationException() = default;

                // cldeException
                virtual const std::string &Name() const noexcept override;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_SEGMENTATION_EXCEPTION_SEGMENTATIONEXCEPTION_H
