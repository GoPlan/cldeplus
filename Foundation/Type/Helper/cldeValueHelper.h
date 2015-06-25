//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_HELPER_CLDEVALUEHELPER_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_HELPER_CLDEVALUEHELPER_H

#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Helper {

                class cldeValueHelper {

                    cldeValueHelper() = delete;
                    cldeValueHelper(const cldeValueHelper &) = delete;
                    cldeValueHelper(cldeValueHelper &&) = delete;
                    cldeValueHelper &operator=(const cldeValueHelper &) = delete;
                    cldeValueHelper &operator=(cldeValueHelper &&) = delete;
                    virtual ~cldeValueHelper() = delete;

                public:
                    static SPtrCldeValue CopySPtrValue(const SPtrCldeValue &sptrValue);

                };

            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_HELPER_CLDEVALUEHELPER_H
