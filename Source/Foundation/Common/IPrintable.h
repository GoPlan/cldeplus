//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_COMMON_IPRINTABLE_H
#define CLDEPLUS_FOUNDATION_COMMON_IPRINTABLE_H

#include "../../Port/Definitions.h"
#include "IFormatter.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {
            struct IPrintable {
                virtual string ToString() const = 0;
                virtual string ToString(const IFormatter &formatter) const { return formatter.Format(*this); };
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_COMMON_IPRINTABLE_H
