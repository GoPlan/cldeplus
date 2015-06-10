//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_ICOMPARABLE_H
#define CLOUD_E_CPLUS_ICOMPARABLE_H

namespace Cloude {
    namespace Foundation {
        namespace Common {
            class IEquatable {
            public:
                virtual bool Equal(const IEquatable &rhs) = 0;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ICOMPARABLE_H
