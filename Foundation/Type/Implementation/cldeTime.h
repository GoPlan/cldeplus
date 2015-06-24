//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETIME_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETIME_H

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeTime {

                public:
                    cldeTime() = default;
                    cldeTime(const cldeTime &) = default;
                    cldeTime(cldeTime &&) = default;
                    cldeTime &operator=(const cldeTime &) = default;
                    cldeTime &operator=(cldeTime &&) = default;
                    ~cldeTime() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETIME_H
