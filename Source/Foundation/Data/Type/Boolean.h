//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H

#include "../NumericValue.h"

namespace CLDEPlus {
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


#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_BOOLEAN_H
