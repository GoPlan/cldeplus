//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_TIMEBASEDVALUE_H
#define CLDEPLUS_FOUNDATION_DATA_TIMEBASEDVALUE_H

#include "Value.h"
#include "../Common/IComparable.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            class TimeBasedValue : public Value,
                                   public Common::IComparable {

            public:
                using TSDate = struct {
                    int year{0};
                    int month{0};
                    int day{0};
                };
                using TSTime = struct {
                    int hour{0};
                    int minute{0};
                    int second{0};
                    int offset{0};
                    int milliSecs{0};
                };
                using TSDateTime = struct {
                    TSDate date;
                    TSTime time;
                };

            public:
                TimeBasedValue(ValueType dataType, size_t size);
                TimeBasedValue(const TimeBasedValue &) = default;
                TimeBasedValue(TimeBasedValue &&) = default;
                TimeBasedValue &operator=(const TimeBasedValue &) = default;
                TimeBasedValue &operator=(TimeBasedValue &&) = default;
                virtual ~TimeBasedValue() = default;

                // Value
                const ValueCategory &getCategory() const override;
                bool isNumeric() const override;

            protected:
                static ValueCategory _category;

            };
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_TIMEBASEDVALUE_H
