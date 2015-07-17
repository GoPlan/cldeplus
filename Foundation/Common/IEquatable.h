//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_COMMON_ICOMPARABLE_H
#define CLOUD_E_PLUS_FOUNDATION_COMMON_ICOMPARABLE_H

namespace Cloude {
    namespace Foundation {
        namespace Common {

            class IEquatable : public std::binary_function<IEquatable, IEquatable, bool> {

            public:
                virtual bool Equal(const IEquatable &rhs) const = 0;
            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_COMMON_ICOMPARABLE_H
