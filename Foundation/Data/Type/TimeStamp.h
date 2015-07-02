//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIMESTAMP_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIMESTAMP_H

#include <Foundation/Data/Value.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class TimeStamp : public Value {

                public:
                    TimeStamp() = default;
                    TimeStamp(const TimeStamp &) = default;
                    TimeStamp(TimeStamp &&) = default;
                    TimeStamp &operator=(const TimeStamp &) = default;
                    TimeStamp &operator=(TimeStamp &&) = default;
                    virtual ~TimeStamp() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIMESTAMP_H
