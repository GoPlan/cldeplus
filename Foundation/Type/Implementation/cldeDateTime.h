//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H

#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeDateTime : public cldeValue {

                public:
                    cldeDateTime() = default;
                    cldeDateTime(const cldeDateTime &) = default;
                    cldeDateTime(cldeDateTime &&) = default;
                    cldeDateTime &operator=(const cldeDateTime &) = default;
                    cldeDateTime &operator=(cldeDateTime &&) = default;
                    ~cldeDateTime() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
