//
// Created by LE, Duc Anh on 11/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_COMMON_IPRIMITIVEASSIGNABLE_H
#define CLDEPLUS_FOUNDATION_COMMON_IPRIMITIVEASSIGNABLE_H

namespace CLDEPlus {
    namespace Foundation {
        namespace Common {

            template<class T>
            struct IPrimitiveAssignable {
                virtual T &operator=(bool value) = 0;
                virtual T &operator=(double value) = 0;
                virtual T &operator=(float value) = 0;
                virtual T &operator=(int16 value) = 0;
                virtual T &operator=(int32 value) = 0;
                virtual T &operator=(int64 value) = 0;
                virtual T &operator=(uint16 value) = 0;
                virtual T &operator=(uint32 value) = 0;
                virtual T &operator=(uint64 value) = 0;
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_COMMON_IPRIMITIVEASSIGNABLE_H
