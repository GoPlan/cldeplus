//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_CLDENUMERICVALUE_H
#define CLOUD_E_CPLUS_CLDENUMERICVALUE_H

#include <Foundation/Common/IComputable.h>
#include "cldeValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            class cldeNumericValue : public cldeValue,
                                     public Common::IComputable<cldeValue> {
            public:
                cldeNumericValue(cldeValueType dataType, size_t length);
                virtual ~cldeNumericValue() = default;
                cldeNumericValue(const cldeNumericValue &rhs) = default;
                cldeNumericValue &operator=(const cldeNumericValue &rhs) = default;

                virtual cldeValueCategory getCategory() override;
                bool isNumeric() override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_CLDENUMERICVALUE_H
