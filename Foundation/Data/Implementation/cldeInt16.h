//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEINT16_H
#define CLOUD_E_CPLUS_CLDEINT16_H

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeInt16 {
                public:
                    cldeInt16() = default;
                    virtual ~cldeInt16() = default;
                    cldeInt16(const cldeInt16 &rhs) = default;
                    cldeInt16 &operator=(const cldeInt16 &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEINT16_H
