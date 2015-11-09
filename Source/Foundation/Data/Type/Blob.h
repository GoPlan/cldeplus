//
// Created by LE, Duc Anh on 6/17/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_BLOB_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_BLOB_H

#include "../Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Blob : public Value {

                    void *_buffer = nullptr;

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


#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_BLOB_H
