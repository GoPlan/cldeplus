//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLDEPLUS_FOUNDATION_COMMON_ICOMPUTABLE_H
#define CLDEPLUS_FOUNDATION_COMMON_ICOMPUTABLE_H

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {

            template<class T>
            struct IComputable {
                virtual T &operator+(T const &rhs) = 0;
                virtual T &operator-(T const &rhs) = 0;
                virtual T &operator*(T const &rhs) = 0;
                virtual T &operator/(T const &rhs) = 0;
                virtual T &operator%(T const &rhs) = 0;
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_COMMON_ICOMPUTABLE_H
