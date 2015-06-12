//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDECHARACTERVALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDECHARACTERVALUE_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "cldeValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Type {
            class cldeCharacterValue : public cldeValue {
            public:
                cldeCharacterValue(cldeValueType dataType, size_t length);
                virtual ~cldeCharacterValue() = default;
                cldeCharacterValue(const cldeCharacterValue &rhs) = default;
                cldeCharacterValue &operator=(const cldeCharacterValue &rhs) = default;

                const cldeValueCategory & getCategory() const override;
                bool isNumeric() const override;

                virtual cldeValue &operator+(const cldeValue &rhs) override;
                virtual cldeValue &operator-(const cldeValue &rhs) override;
                virtual cldeValue &operator*(const cldeValue &rhs) override;
                virtual cldeValue &operator/(const cldeValue &rhs) override;
                virtual cldeValue &operator%(const cldeValue &rhs) override;

            private:
                static cldeValueCategory _category;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDECHARACTERVALUE_H
