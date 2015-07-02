//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_COMAPARE_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_COMAPARE_H

#include <Foundation/Data/Value.h>
#include "Greater.h"
#include "Less.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Comparer {

                class Compare : public std::binary_function<SPtrValue, SPtrValue, bool> {

                public:
                    Compare() = default;
                    bool operator()(const SPtrValue &lhs, const SPtrValue &rhs) const {
                        Less lesser;
                        return !lesser(lhs, rhs) && !lesser(rhs, lhs);
                    }
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_COMPARER_COMAPARE_H
