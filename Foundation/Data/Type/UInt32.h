//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT32_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT32_H

#include <Foundation/Data/NumericValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class UInt32 : public NumericValue {

                    uint32_t _value;
                    mutable std::string _string;

                public:
                    explicit UInt32(int value);
                    UInt32(const UInt32 &) = default;
                    UInt32(UInt32 &&) = default;
                    UInt32 &operator=(const UInt32 &) = default;
                    UInt32 &operator=(UInt32 &&) = default;
                    ~UInt32() = default;

                    // Value
                    virtual void *RawPointerToValueBuffer() override;

                    // IEquatable
                    virtual bool Equal(const Common::IEquatable &rhs) const override;

                    // IPrintable
                    virtual const std::string CopyToString() const override;
                    virtual const std::string &ToString() const override;
                    virtual const char *ToCString() const override;

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

#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_UINT32_H
