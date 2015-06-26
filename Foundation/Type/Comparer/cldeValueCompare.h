//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUECOMAPRE_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUECOMAPRE_H

#include <Foundation/Type/cldeValue.h>
#include "cldeValueGreater.h"
#include "cldeValueLess.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Comparer {

                class cldeValueCompare : public std::binary_function<SPtrValue, SPtrValue, bool> {

                public:
                    cldeValueCompare() = default;
                    bool operator()(const SPtrValue &lhs, const SPtrValue &rhs) const {
                        cldeValueLess lesser;
                        return !lesser(lhs, rhs) && !lesser(rhs, lhs);
                    }
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_CLDEVALUECOMAPRE_H
