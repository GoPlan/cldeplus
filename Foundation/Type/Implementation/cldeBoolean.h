//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBOOLEAN_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBOOLEAN_H

#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeBoolean : public cldeValue {
                    bool _value;

                public:
                    cldeBoolean() = default;
                    cldeBoolean(const cldeBoolean &) = default;
                    cldeBoolean(cldeBoolean &&) = default;
                    cldeBoolean &operator=(const cldeBoolean &) = default;
                    cldeBoolean &operator=(cldeBoolean &&) = default;
                    ~cldeBoolean() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBOOLEAN_H
