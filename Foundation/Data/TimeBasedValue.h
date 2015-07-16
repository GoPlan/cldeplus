//
// Created by LE, Duc Anh on 7/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_DATA_TIMEBASEDVALUE_H
#define CLOUD_E_PLUS_FOUNDATION_DATA_TIMEBASEDVALUE_H

#include "Value.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            class TimeBasedValue : public Value {

            public:
                using TSDate = struct {
                    int16_t year;
                    int8_t month;
                    int8_t day;
                };
                using TSTime = struct {
                    int8_t hour;
                    int8_t minute;
                    int8_t second;
                    int8_t offset;
                    int16_t milliSecs;
                };
                using TSDateTime = struct {
                    TSDate date;
                    TSTime time;
                };

            public:
                TimeBasedValue() = default;
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


#endif //CLOUD_E_PLUS_FOUNDATION_DATA_TIMEBASEDVALUE_H
