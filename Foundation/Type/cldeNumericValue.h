//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDENUMERICVALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDENUMERICVALUE_H

#include <Foundation/Common/IComputable.h>
#include "cldeValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {

            class cldeNumericValue : public cldeValue {
                static cldeValueCategory _category;

            public:
                cldeNumericValue(cldeValueType dataType, size_t length);
                cldeNumericValue(const cldeNumericValue &) = default;
                cldeNumericValue(cldeNumericValue &&) = default;
                cldeNumericValue &operator=(const cldeNumericValue &) = default;
                cldeNumericValue &operator=(cldeNumericValue &&) = default;
                virtual ~cldeNumericValue() = default;

                const cldeValueCategory &getCategory() const override;
                bool isNumeric() const override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDENUMERICVALUE_H
