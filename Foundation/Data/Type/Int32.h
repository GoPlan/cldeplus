//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT32_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT32_H

#include <Foundation/Data/NumericValue.h>
#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Int32 : public NumericValue {

                    int32_t _value;
                    mutable std::string _string;

                public:
                    explicit Int32(int32_t value);
                    Int32(const Int32 &) = default;
                    Int32(Int32 &&) = default;
                    Int32 &operator=(const Int32 &) = default;
                    Int32 &operator=(Int32 &&) = default;
                    ~Int32() = default;

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

#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT32_H
