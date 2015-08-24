//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_COMMON_IPRINTABLE_H
#define CLOUD_E_PLUS_FOUNDATION_COMMON_IPRINTABLE_H

#include <string>
#include "IFormatter.h"

namespace Cloude {
    namespace Foundation {
        namespace Common {
            struct IPrintable {
                virtual std::string ToString() const = 0;
                virtual std::string ToString(const IFormatter &formatter) const { return formatter.Format(*this); };
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_COMMON_IPRINTABLE_H
