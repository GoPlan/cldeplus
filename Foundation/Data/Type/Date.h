//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATE_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATE_H

#include <Foundation/Data/Value.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Date : public Value {

                public:
                    Date() = default;
                    Date(const Date &) = default;
                    Date(Date &&) = default;
                    Date &operator=(const Date &) = default;
                    Date &operator=(Date &&) = default;
                    ~Date() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATE_H
