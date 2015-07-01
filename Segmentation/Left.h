//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_LEFT_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_LEFT_H

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            class Left {

            public:
                Left() = default;
                Left(const Left &) = default;
                Left(Left &&) = default;
                Left &operator=(const Left &) = default;
                Left &operator=(Left &&) = default;
                virtual ~Left() = default;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_LEFT_H
