/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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

                // IPrimitiveAssignable
                virtual Value &operator=(bool value) override;
                virtual Value &operator=(double value) override;
                virtual Value &operator=(float value) override;
                virtual Value &operator=(int16 value) override;
                virtual Value &operator=(int32 value) override;
                virtual Value &operator=(int64 value) override;
                virtual Value &operator=(uint16 value) override;
                virtual Value &operator=(uint32 value) override;
                virtual Value &operator=(uint64 value) override;

            protected:
                static ValueCategory _category;

            };
        }
    }
}


#endif //CLDEPLUS_FOUNDATION_DATA_TIMEBASEDVALUE_H
