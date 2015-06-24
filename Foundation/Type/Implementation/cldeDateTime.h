//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H

namespace Cloude {
    namespace Foundation {
        namespace Type{
            namespace Implementation {

                class cldeDateTime {

                public:
                    cldeDateTime() = default;
                    cldeDateTime(const cldeDateTime &) = default;
                    cldeDateTime(cldeDateTime &&) = default;
                    cldeDateTime &operator=(const cldeDateTime &) = default;
                    cldeDateTime &operator=(cldeDateTime &&) = default;
                    virtual ~cldeDateTime() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
