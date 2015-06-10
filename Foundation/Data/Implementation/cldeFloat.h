//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDEFLOAT_H
#define CLOUD_E_CPLUS_CLDEFLOAT_H

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeFloat {
                public:
                    cldeFloat() = default;
                    virtual ~cldeFloat() = default;
                    cldeFloat(const cldeFloat &rhs) = default;
                    cldeFloat &operator=(const cldeFloat &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDEFLOAT_H
