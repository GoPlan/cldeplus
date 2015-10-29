//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_NUMERICVALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_NUMERICVALUE_H

#include "../Common/IComputable.h"
#include "Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            class NumericValue : public Value {

                static ValueCategory _category;

            public:
                NumericValue(ValueType dataType, size_t size);
                NumericValue(const NumericValue &) = default;
                NumericValue(NumericValue &&) = default;
                NumericValue &operator=(const NumericValue &) = default;
                NumericValue &operator=(NumericValue &&) = default;
                virtual ~NumericValue() = default;

                const ValueCategory &getCategory() const override;
                bool isNumeric() const override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_NUMERICVALUE_H
