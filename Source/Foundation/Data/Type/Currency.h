//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_CURRENCY_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_CURRENCY_H

#include "../Value.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Currency : public Value {

                public:
                    Currency() = default;
                    Currency(const Currency &) = default;
                    Currency(Currency &&) = default;
                    Currency &operator=(const Currency &) = default;
                    Currency &operator=(Currency &&) = default;
                    ~Currency() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_CURRENCY_H
