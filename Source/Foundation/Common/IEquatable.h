//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_COMMON_ICOMPARABLE_H
#define CLDEPLUS_FOUNDATION_COMMON_ICOMPARABLE_H

#include "../../Port/Definitions.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {

            struct IEquatable : public std::binary_function<IEquatable, IEquatable, bool> {
                virtual bool Equal(const IEquatable &rhs) const = 0;
            };
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_COMMON_ICOMPARABLE_H
