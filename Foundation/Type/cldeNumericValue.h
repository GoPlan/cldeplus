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
            public:
                cldeNumericValue(cldeValueType dataType, size_t length);
                virtual ~cldeNumericValue() = default;
                cldeNumericValue(const cldeNumericValue &rhs) = default;
                cldeNumericValue &operator=(const cldeNumericValue &rhs) = default;

                const cldeValueCategory &getCategory() const override;
                bool isNumeric() const override;

            private:
                static cldeValueCategory _category;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDENUMERICVALUE_H
