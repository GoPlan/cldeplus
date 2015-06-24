//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBOOLEAN_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBOOLEAN_H

namespace Cloude {
    namespace Foundation {
        namespace Type{
            namespace Implementation {

                class cldeBoolean {

                public:
                    cldeBoolean() = default;
                    cldeBoolean(const cldeBoolean &) = default;
                    cldeBoolean(cldeBoolean &&) = default;
                    cldeBoolean &operator=(const cldeBoolean &) = default;
                    cldeBoolean &operator=(cldeBoolean &&) = default;
                    virtual ~cldeBoolean() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBOOLEAN_H
