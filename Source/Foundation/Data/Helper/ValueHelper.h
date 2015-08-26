//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_HELPER_VALUEHELPER_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_HELPER_VALUEHELPER_H

#include "../Value.h"

namespace Cloude {
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


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_HELPER_VALUEHELPER_H
