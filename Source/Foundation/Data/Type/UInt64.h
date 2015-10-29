//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_UINT64_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_UINT64_H

#include "../NumericValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class UInt64 : public NumericValue {

                    uint64_t _value;

                public:
                    explicit UInt64(uint64_t value);
                    UInt64(const UInt64 &) = default;
                    UInt64(UInt64 &&) = default;
                    UInt64 &operator=(const UInt64 &) = default;
                    UInt64 &operator=(UInt64 &&) = default;
                    ~UInt64() = default;

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

#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_UINT64_H
