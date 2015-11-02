//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_DATETIME_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_DATETIME_H

#include "../TimeBasedValue.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class DateTime : public TimeBasedValue {

                    TimeBasedValue::TSDateTime _dateTime;

                public:
                    DateTime(int year, int month, int day);
                    DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int offset);

                    DateTime();
                    DateTime(const DateTime &) = default;
                    DateTime(DateTime &&) = default;
                    DateTime &operator=(const DateTime &) = default;
                    DateTime &operator=(DateTime &&) = default;
                    ~DateTime() = default;

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

#endif //CLDEPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
