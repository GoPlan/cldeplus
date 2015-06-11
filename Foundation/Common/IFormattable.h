//
// Created by LE, Duc Anh on 6/11/15.
//

#ifndef CLOUD_E_CPLUS_IFORMATTABLE_H
#define CLOUD_E_CPLUS_IFORMATTABLE_H

#include <iosfwd>

namespace Cloude {
    namespace Foundation {
        namespace Common {
            class IFormattable {
            public:
                virtual std::string CopyFormatedString();
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_IFORMATTABLE_H
