//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include "Value.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            class CharacterValue : public Value {
                static ValueCategory _category;

            public:
                CharacterValue(ValueType dataType, size_t length);
                CharacterValue(const CharacterValue &) = default;
                CharacterValue(CharacterValue &&) = default;
                CharacterValue &operator=(const CharacterValue &) = default;
                CharacterValue &operator=(CharacterValue &&) = default;
                virtual ~CharacterValue() = default;

                const ValueCategory &getCategory() const override;
                bool isNumeric() const override;

                virtual Value &operator+(const Value &rhs) override;
                virtual Value &operator-(const Value &rhs) override;
                virtual Value &operator*(const Value &rhs) override;
                virtual Value &operator/(const Value &rhs) override;
                virtual Value &operator%(const Value &rhs) override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H
