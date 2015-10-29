//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_TYPE_HELPER_VALUEHELPER_H
#define CLDEPLUS_FOUNDATION_TYPE_HELPER_VALUEHELPER_H

#include "../Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {
                struct ValueHelper {
                    static SPtrValue CopySPtrValue(const SPtrValue &sptrValue);
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_TYPE_HELPER_VALUEHELPER_H
