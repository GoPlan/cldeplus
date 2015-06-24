//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT32_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT32_H

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeUInt32 {

                public:
                    cldeUInt32() = default;
                    cldeUInt32(const cldeUInt32 &) = default;
                    cldeUInt32(cldeUInt32 &&) = default;
                    cldeUInt32 &operator=(const cldeUInt32 &) = default;
                    cldeUInt32 &operator=(cldeUInt32 &&) = default;
                    ~cldeUInt32() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT32_H
