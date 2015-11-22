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

#ifndef CLDEPLUS_DATA_TYPE_DATE_H
#define CLDEPLUS_DATA_TYPE_DATE_H

#include "../TimeBasedValue.h"

namespace CLDEPlus {
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
                virtual bool LessThan(IComparable const &target) const override;
                virtual bool GreaterThan(IComparable const &target) const override;
                virtual bool EquivalentTo(IComparable const &target) const override;
            };
        }
    }
}


#endif //CLDEPLUS_DATA_TYPE_DATE_H
