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

#ifndef CLDEPLUS_COMMONS_H
#define CLDEPLUS_COMMONS_H

namespace CLDEPlus {

    enum CommonBufferSize {
        ONE = 1,
        TWO = 2,
        EIGHT = 8,
        SIXTEEN = 16,
        THIRTYTWO = 32,
        SIXTYFOUR = 64,
        EIGHTY = 80,
        ONEHUNDREDTWENTYEIGHT = 128,
        TWOHUNDREDFIFTYSIX = 256,
    };

    struct IComparable {
        virtual bool LessThan(IComparable const &target) const = 0;
        virtual bool GreaterThan(IComparable const &target) const = 0;
        virtual bool EquivalentTo(IComparable const &target) const = 0;
    };

    template<class T>
    struct IComputable {
        virtual T &operator+(T const &rhs) = 0;
        virtual T &operator-(T const &rhs) = 0;
        virtual T &operator*(T const &rhs) = 0;
        virtual T &operator/(T const &rhs) = 0;
        virtual T &operator%(T const &rhs) = 0;
    };

    template<class T>
    struct IPrimitiveAssignable {
        virtual T &operator=(bool value) = 0;
        virtual T &operator=(double value) = 0;
        virtual T &operator=(float value) = 0;
        virtual T &operator=(int16 value) = 0;
        virtual T &operator=(int32 value) = 0;
        virtual T &operator=(int64 value) = 0;
        virtual T &operator=(uint16 value) = 0;
        virtual T &operator=(uint32 value) = 0;
        virtual T &operator=(uint64 value) = 0;
    };

    struct IEquatable : public std::binary_function<IEquatable, IEquatable, bool> {
        virtual bool Equal(IEquatable  const &rhs) const = 0;
    };

    struct IPrintable;

    struct IFormatter {
        virtual string Format( IPrintable const&printable) const = 0;
    };

    struct IPrintable {
        virtual string ToString() const = 0;
        virtual string ToString(IFormatter const &formatter) const { return formatter.Format(*this); };
    };
}

#endif //CLDEPLUS_COMMONS_H
