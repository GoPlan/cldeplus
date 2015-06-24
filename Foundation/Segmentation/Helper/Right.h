//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_RIGHT_H
#define CLOUD_E_PLUS_RIGHT_H

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class Right {

                public:
                    Right() = default;
                    Right(const Right &) = default;
                    Right(Right &&) = default;
                    Right &operator=(const Right &) = default;
                    Right &operator=(Right &&) = default;
                    virtual ~Right() = default;
                };

            }
        }
    }
}


#endif //CLOUD_E_PLUS_RIGHT_H
