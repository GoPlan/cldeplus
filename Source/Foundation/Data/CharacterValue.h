//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H

#include "../Exception/CLDENonSupportedFunctionException.h"
#include "Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            class CharacterValue : public Value {
                static ValueCategory _category;

            public:
                CharacterValue(ValueType dataType, size_t size);
                CharacterValue(const CharacterValue &) = default;
                CharacterValue(CharacterValue &&) = default;
                CharacterValue &operator=(const CharacterValue &) = default;
                CharacterValue &operator=(CharacterValue &&) = default;
                virtual ~CharacterValue() = default;

                const ValueCategory &getCategory() const override;
                bool isNumeric() const override;

                // IComputable
                virtual Value &operator+(const Value &rhs) override;
                virtual Value &operator-(const Value &rhs) override;
                virtual Value &operator*(const Value &rhs) override;
                virtual Value &operator/(const Value &rhs) override;
                virtual Value &operator%(const Value &rhs) override;

                // IPrimitiveAssignable
                virtual Value &operator=(bool value) override;
                virtual Value &operator=(double value) override;
                virtual Value &operator=(float value) override;
                virtual Value &operator=(int16 value) override;
                virtual Value &operator=(int32 value) override;
                virtual Value &operator=(int64 value) override;
                virtual Value &operator=(uint16 value) override;
                virtual Value &operator=(uint32 value) override;
                virtual Value &operator=(uint64 value) override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CHARACTERVALUE_H
