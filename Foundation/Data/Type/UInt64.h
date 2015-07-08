//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT64_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT64_H

#include <Foundation/Data/NumericValue.h>

namespace Cloude {
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
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) const override;

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

#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT64_H
