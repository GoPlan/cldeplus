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

#ifndef CLDEPLUS_DATA_TYPE_DATETIME_H
#define CLDEPLUS_DATA_TYPE_DATETIME_H

#include "../TimeBasedValue.h"

namespace CLDEPlus {
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
                virtual bool LessThan(IComparable const &target) const override;
                virtual bool GreaterThan(IComparable const &target) const override;
                virtual bool EquivalentTo(IComparable const &target) const override;
            };
        }
    }
}

#endif //CLDEPLUS_DATA_TYPE_DATETIME_H
