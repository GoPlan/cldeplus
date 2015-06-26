//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUEEQUAL_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUEEQUAL_H

#include <Foundation/Type/cldeValue.h>
#include "cldeValueGreater.h"
#include "cldeValueLess.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Comparer {
                struct cldeValueEqual : std::binary_function<SPtrValue, SPtrValue, bool> {
                    bool operator()(const SPtrValue &lhs, const SPtrValue &rhs) {
                        cldeValueLess lesser;
                        return !lesser(lhs, rhs) && !lesser(rhs, lhs);
                    };
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUEEQUAL_H
