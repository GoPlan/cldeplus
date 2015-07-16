//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATE_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATE_H

#include <Foundation/Exception/cldeNonSupportedFunctionException.h>
#include <Foundation/Data/TimeBasedValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Date : public TimeBasedValue {

                    TimeBasedValue::TSDate _date;

                public:
                    Date() = default;
                    Date(const Date &) = default;
                    Date(Date &&) = default;
                    Date &operator=(const Date &) = default;
                    Date &operator=(Date &&) = default;
                    ~Date() = default;

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


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATE_H
