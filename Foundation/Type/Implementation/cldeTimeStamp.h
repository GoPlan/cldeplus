//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETIMESTAMP_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETIMESTAMP_H

#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeTimeStamp : public cldeValue {

                public:
                    cldeTimeStamp() = default;
                    cldeTimeStamp(const cldeTimeStamp &) = default;
                    cldeTimeStamp(cldeTimeStamp &&) = default;
                    cldeTimeStamp &operator=(const cldeTimeStamp &) = default;
                    cldeTimeStamp &operator=(cldeTimeStamp &&) = default;
                    virtual ~cldeTimeStamp() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDETIMESTAMP_H
