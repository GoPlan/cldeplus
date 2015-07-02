//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIME_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIME_H

#include <Foundation/Data/Value.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Time : public Value {

                public:
                    Time() = default;
                    Time(const Time &) = default;
                    Time(Time &&) = default;
                    Time &operator=(const Time &) = default;
                    Time &operator=(Time &&) = default;
                    ~Time() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIME_H
