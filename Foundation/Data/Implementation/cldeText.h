//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDETEXT_H
#define CLOUD_E_CPLUS_CLDETEXT_H

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Implementation {
                class cldeText {
                public:
                    cldeText() = default;
                    virtual ~cldeText() = default;
                    cldeText(const cldeText &rhs) = default;
                    cldeText &operator=(const cldeText &rhs) = default;

                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDETEXT_H
