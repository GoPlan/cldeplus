//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIME_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIME_H

#include <Foundation/Data/TimeBasedValue.h>

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Type {

                class Time : public TimeBasedValue {

                    TimeBasedValue::TSTime _time;
                    bool _hasOffSet;

                public:
                    Time(int hour, int minute, int second, int millisecond = 0,
                         bool hasOffSet = false, int offset = 0);

                    Time();
                    Time(const Time &) = default;
                    Time(Time &&) = default;
                    Time &operator=(const Time &) = default;
                    Time &operator=(Time &&) = default;
                    ~Time() = default;

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


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TYPE_TIME_H