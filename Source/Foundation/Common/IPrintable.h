//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_COMMON_IPRINTABLE_H
#define CLDEPLUS_FOUNDATION_COMMON_IPRINTABLE_H

#include <string>
#include "IFormatter.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {
            struct IPrintable {
                virtual std::string ToString() const = 0;
                virtual std::string ToString(const IFormatter &formatter) const { return formatter.Format(*this); };
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_COMMON_IPRINTABLE_H
