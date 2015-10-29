//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLDEPLUS_FOUNDATION_COMMON_IFORMATTER_H
#define CLDEPLUS_FOUNDATION_COMMON_IFORMATTER_H

#include <string>

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {

            class IPrintable;

            struct IFormatter {
                virtual std::string Format(const IPrintable &printable) const = 0;
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_COMMON_IFORMATTER_H
