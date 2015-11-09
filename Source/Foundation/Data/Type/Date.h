//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TYPE_DATE_H
#define CLDEPLUS_FOUNDATION_DATA_TYPE_DATE_H

#include "../TimeBasedValue.h"

namespace CLDEPlus {
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
                    Date &operator=(Date const &) = default;
                    Date &operator=(Date &&) = default;
                    ~Date() = default;

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


#endif //CLDEPLUS_FOUNDATION_DATA_TYPE_DATE_H
