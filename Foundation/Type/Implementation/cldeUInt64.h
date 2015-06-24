//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT64_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT64_H

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeUInt64 {

                public:
                    cldeUInt64() = default;
                    cldeUInt64(const cldeUInt64 &) = default;
                    cldeUInt64(cldeUInt64 &&) = default;
                    cldeUInt64 &operator=(const cldeUInt64 &) = default;
                    cldeUInt64 &operator=(cldeUInt64 &&) = default;
                    ~cldeUInt64() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT64_H
