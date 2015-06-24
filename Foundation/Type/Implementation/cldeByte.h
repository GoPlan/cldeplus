//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBYTE_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBYTE_H

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeByte {

                public:
                    cldeByte() = default;
                    cldeByte(const cldeByte &) = default;
                    cldeByte(cldeByte &&) = default;
                    cldeByte &operator=(const cldeByte &) = default;
                    cldeByte &operator=(cldeByte &&) = default;
                    virtual ~cldeByte() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEBYTE_H
