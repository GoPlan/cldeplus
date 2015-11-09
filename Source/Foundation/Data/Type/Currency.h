//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_CURRENCY_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_CURRENCY_H

#include "../Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Currency : public Value {

                public:
                    Currency() = default;
                    Currency(Currency const &) = default;
                    Currency(Currency &&) = default;
                    Currency &operator=(Currency const &) = default;
                    Currency &operator=(Currency &&) = default;
                    ~Currency() = default;
                };
            }
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_CURRENCY_H
