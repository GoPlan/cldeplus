//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT64_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT64_H

#include <Foundation/Data/NumericValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Int64 : public NumericValue {

                    int64_t _value;
                    mutable std::string _string;

                public:
                    explicit Int64(int64_t value);
                    Int64(const Int64 &) = default;
                    Int64(Int64 &&) = default;
                    Int64 &operator=(const Int64 &) = default;
                    Int64 &operator=(Int64 &&) = default;
                    ~Int64() = default;

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


#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_INT64_H
