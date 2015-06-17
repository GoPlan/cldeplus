//
// Created by LE, Duc Anh on 6/17/15.
//

#ifndef CLOUD_E_PLUS_CLDEBLOB_H
#define CLOUD_E_PLUS_CLDEBLOB_H

#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeBlob : public cldeValue {
                    void *buffer;

                public:
                    cldeBlob() = default;
                    cldeBlob(const cldeBlob &) = default;
                    cldeBlob(cldeBlob &&) = default;
                    cldeBlob &operator=(const cldeBlob &) = default;
                    cldeBlob &operator=(cldeBlob &&) = default;
                    ~cldeBlob() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_CLDEBLOB_H
