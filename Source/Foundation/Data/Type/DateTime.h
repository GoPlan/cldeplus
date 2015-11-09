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
                    DateTime(DateTime const &) = default;
                    DateTime(DateTime &&) = default;
                    DateTime &operator=(DateTime const &) = default;
                    DateTime &operator=(DateTime &&) = default;
                    ~DateTime() = default;

                    // Value
                    virtual void *PointerToBuffer() override;

                    // IPrintable
                    virtual string ToString() const override;

                    // IComputable
                    virtual Value &operator+(Value const &rhs) override;
                    virtual Value &operator-(Value const &rhs) override;
                    virtual Value &operator*(Value const &rhs) override;
                    virtual Value &operator/(Value const &rhs) override;
                    virtual Value &operator%(Value const &rhs) override;

                    // IComparable
                    virtual bool LessThan(Common::IComparable const &target) const override;
                    virtual bool GreaterThan(Common::IComparable const &target) const override;
                    virtual bool EquivalentTo(Common::IComparable const &target) const override;
                };
            }
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_TYPE_IMPLEMENTATION_CLDEDATETIME_H
