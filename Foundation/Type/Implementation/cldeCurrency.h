//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDECURRENCY_H
#define CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDECURRENCY_H

#include <Foundation/Type/cldeValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Implementation {

                class cldeCurrency : public cldeValue {

                public:
                    cldeCurrency() = default;
                    cldeCurrency(const cldeCurrency &) = default;
                    cldeCurrency(cldeCurrency &&) = default;
                    cldeCurrency &operator=(const cldeCurrency &) = default;
                    cldeCurrency &operator=(cldeCurrency &&) = default;
                    ~cldeCurrency() = default;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDECURRENCY_H
