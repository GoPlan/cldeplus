//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT16_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT16_H

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeUInt16 {

                public:
                    cldeUInt16() = default;
                    cldeUInt16(const cldeUInt16 &) = default;
                    cldeUInt16(cldeUInt16 &&) = default;
                    cldeUInt16 &operator=(const cldeUInt16 &) = default;
                    cldeUInt16 &operator=(cldeUInt16 &&) = default;
                    ~cldeUInt16() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEUINT16_H
