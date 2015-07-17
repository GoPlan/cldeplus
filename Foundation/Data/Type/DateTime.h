//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATETIME_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_DATETIME_H

#include <Foundation/Data/TimeBasedValue.h>
#include <Foundation/Exception/cldeNonSupportedFunctionException.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class DateTime : public TimeBasedValue {

                    TimeBasedValue::TSDateTime _dateTime;
                    bool _hasOffSet;

                public:
                    DateTime(int year, int month, int day);
                    DateTime(int year, int month, int day,
                             int hour, int minute, int second, int millisecond = 0,
                             bool hasOffSet = false, int offset = 0);

                    DateTime();
                    DateTime(const DateTime &) = default;
                    DateTime(DateTime &&) = default;
                    DateTime &operator=(const DateTime &) = default;
                    DateTime &operator=(DateTime &&) = default;
                    ~DateTime() = default;

                    // Value
                    virtual void *PointerToBuffer();

                    // IPrintable
                    virtual std::string ToString() const;

                    // IComputable
                    virtual Value &operator+(const Value &rhs);
                    virtual Value &operator-(const Value &rhs);
                    virtual Value &operator*(const Value &rhs);
                    virtual Value &operator/(const Value &rhs);
                    virtual Value &operator%(const Value &rhs);

                    // IComparable
                    virtual bool LessThan(const Common::IComparable &target) const override;
                    virtual bool GreaterThan(const Common::IComparable &target) const override;
                    virtual bool EquivalentTo(const Common::IComparable &target) const override;
                };
            }
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
