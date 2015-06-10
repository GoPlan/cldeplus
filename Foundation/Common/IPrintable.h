//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_IPRINTABLE_H
#define CLOUD_E_CPLUS_IPRINTABLE_H

#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Common {
            class IPrintable {
            public:
                virtual const std::string CopyToString() const = 0;
                virtual const std::string &ToString() const = 0;
                virtual void SetValueToString(const char *value) = 0;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_IPRINTABLE_H
