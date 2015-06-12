//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_COMMON_ICOMPUTABLE_H
#define CLOUD_E_CPLUS_FOUNDATION_COMMON_ICOMPUTABLE_H

namespace Cloude {
    namespace Foundation {
        namespace Common {

            template<class T>
            class IComputable {

            public:
                virtual T &operator+(const T &rhs) = 0;
                virtual T &operator-(const T &rhs) = 0;
                virtual T &operator*(const T &rhs) = 0;
                virtual T &operator/(const T &rhs) = 0;
                virtual T &operator%(const T &rhs) = 0;
            };
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_ICOMPUTABLE_H
