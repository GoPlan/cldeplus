//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_FLOAT_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_FLOAT_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Float : public NumericValue {

                    float _value;

                public:
                    explicit Float(float value);
                    Float(const Float &) = default;
                    Float(Float &&) = default;
                    Float &operator=(const Float &) = default;
                    Float &operator=(Float &&) = default;
                    ~Float() = default;

                    // Value
                    virtual void *PointerToBuffer() override;

                    // IPrintable
                    virtual string ToString() const override;

                    // IComputable
                    virtual Value &operator+(const Value &rhs) override;
                    virtual Value &operator-(const Value &rhs) override;
                    virtual Value &operator*(const Value &rhs) override;
                    virtual Value &operator/(const Value &rhs) override;
                    virtual Value &operator%(const Value &rhs) override;
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEFLOAT_H
