//
// Created by LE, Duc Anh on 6/17/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BLOB_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BLOB_H

#include "../Value.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Blob : public Value {

                    void *_buffer;

                public:
                    Blob() = default;
                    Blob(const Blob &) = default;
                    Blob(Blob &&) = default;
                    Blob &operator=(const Blob &) = default;
                    Blob &operator=(Blob &&) = default;
                    ~Blob() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BLOB_H
