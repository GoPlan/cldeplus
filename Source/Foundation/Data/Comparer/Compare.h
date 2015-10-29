//
// Created by LE, Duc Anh on 6/26/15.
//

#ifndef CLDEPLUS_FOUNDATION_TYPE_COMPARER_COMAPARE_H
#define CLDEPLUS_FOUNDATION_TYPE_COMPARER_COMAPARE_H

#include "../Value.h"
#include "Greater.h"
#include "Less.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Comparer {

                class Compare : public std::binary_function<SPtrValue, SPtrValue, bool> {

                public:
                    Compare() = default;
                    bool operator()(const SPtrValue &lhs, const SPtrValue &rhs) const {
                        Less lesser;
                        Greater greater;
                        return !lesser(lhs, rhs) && !greater(lhs, rhs);
                    }
                };
            }
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_TYPE_COMPARER_COMAPARE_H
