//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT16_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT16_H

#include <Foundation/Data/NumericValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class UInt16 : public NumericValue {

                    uint16_t _value;

                public:
                    explicit UInt16(uint16_t value);
                    UInt16(const UInt16 &rhs) = default;
                    UInt16(UInt16 &&) = default;
                    UInt16 &operator=(const UInt16 &) = default;
                    UInt16 &operator=(UInt16 &&) = default;
                    ~UInt16() = default;

                    // Value
                    virtual void *RawPointerToValueBuffer() override;

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

#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT16_H
