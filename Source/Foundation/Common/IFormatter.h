//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_COMMON_IFORMATTER_H
#define CLOUD_E_PLUS_FOUNDATION_COMMON_IFORMATTER_H

#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Common {

            class IPrintable;

            struct IFormatter {
                virtual std::string Format(const IPrintable &printable) const = 0;
            };
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_COMMON_IFORMATTER_H
