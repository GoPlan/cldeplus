//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEPOINT_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEPOINT_H

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {
                class cldePoint {
                public:
                    cldePoint() = default;
                    cldePoint(const cldePoint &) = default;
                    cldePoint(cldePoint &&) = default;
                    cldePoint &operator=(const cldePoint &) = default;
                    cldePoint &operator=(cldePoint &&) = default;
                    ~cldePoint() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEPOINT_H
