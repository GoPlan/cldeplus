//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_CROSS_H
#define CLOUD_E_PLUS_CROSS_H

namespace Cloude {
    namespace Segmentation {
        namespace Helper {

            class Cross {

            public:
                Cross() = default;
                Cross(const Cross &) = default;
                Cross(Cross &&) = default;
                Cross &operator=(const Cross &) = default;
                Cross &operator=(Cross &&) = default;
                virtual ~Cross() = default;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_CROSS_H
