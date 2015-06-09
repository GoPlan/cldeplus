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
                virtual const std::string &ToString() const = 0;

            private:
                IPrintable() = delete;
                ~IPrintable() = delete;

                IPrintable(const IPrintable &rhs) = delete;
                IPrintable &operator=(const IPrintable &rhs) = delete;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_IPRINTABLE_H
