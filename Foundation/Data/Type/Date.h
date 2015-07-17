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
                    Date(int year, int month, int day);

                    Date();
                    Date(const Date &) = default;
                    Date(Date &&) = default;
                    Date &operator=(const Date &) = default;
                    Date &operator=(Date &&) = default;
                    ~Date() = default;

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

                    // IComparable
                    virtual bool LessThan(const Common::IComparable &target) const override;
                    virtual bool GreaterThan(const Common::IComparable &target) const override;
                    virtual bool EquivalentTo(const Common::IComparable &target) const override;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATE_H
