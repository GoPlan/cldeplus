//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_COMMON_IPARSABLE_H
#define CLOUD_E_CPLUS_FOUNDATION_COMMON_IPARSABLE_H

namespace Cloude {
    namespace Foundation {
        namespace Common {
            template<typename T>
            class IParsable {
                virtual T Parse() = 0;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_COMMON_IPARSABLE_H
