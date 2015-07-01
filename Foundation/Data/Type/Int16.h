//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT16_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT16_H

#include <Foundation/Data/NumericValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Int16 : public NumericValue {

                    int16_t _value;
                    mutable std::string _string;

                public:
                    explicit Int16(int16_t value);
                    Int16(const Int16 &rhs) = default;
                    Int16(Int16 &&) = default;
                    Int16 &operator=(const Int16 &) = default;
                    Int16 &operator=(Int16 &&) = default;
                    ~Int16() = default;

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


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT16_H
