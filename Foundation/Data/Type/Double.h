//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_DOUBLE_H
#define CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_DOUBLE_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Data/NumericValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Double : public NumericValue {

                    double _value;

                public:
                    explicit Double(double value);
                    Double(const Double &) = default;
                    Double(Double &&) = default;
                    Double &operator=(const Double &) = default;
                    Double &operator=(Double &&) = default;
                    ~Double() = default;

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

#endif //CLOUD_E_CPLUS_FOUNDATION_DATA_TYPE_CLDEDOUBLE_H
