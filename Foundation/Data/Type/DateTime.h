//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATETIME_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATETIME_H

#include <Foundation/Data/Value.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class DateTime : public Value {

                public:
                    DateTime() = default;
                    DateTime(const DateTime &) = default;
                    DateTime(DateTime &&) = default;
                    DateTime &operator=(const DateTime &) = default;
                    DateTime &operator=(DateTime &&) = default;
                    ~DateTime() = default;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
