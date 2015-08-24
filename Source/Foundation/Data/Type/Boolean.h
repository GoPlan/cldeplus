//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H

#include "../NumericValue.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Boolean : public NumericValue {

                    bool _value;

                public:
                    explicit Boolean(bool value);
                    Boolean(const Boolean &) = default;
                    Boolean(Boolean &&) = default;
                    Boolean &operator=(const Boolean &) = default;
                    Boolean &operator=(Boolean &&) = default;
                    ~Boolean() = default;

                    // Value
                    virtual void *PointerToBuffer() override;

                    // IPrintable
                    virtual std::string ToString() const override;

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


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H
