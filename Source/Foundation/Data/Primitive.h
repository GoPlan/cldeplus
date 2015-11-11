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

#ifndef CLDEPLUS_FOUNDATION_DATA_PRIMITIVE_H
#define CLDEPLUS_FOUNDATION_DATA_PRIMITIVE_H

#include "../../Port/Definitions.h"
#include "../Exception/cldeNonSupportedDataTypeException.h"
#include "Value.h"
#include "ValueFactory.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            struct IPrimitive {
                virtual SPtrValue ToValue() const = 0;
            };

            template<typename T>
            class Primitive : public IPrimitive {
                T _value;

            public:
                Primitive(T value) : _value{value} { };
                SPtrValue ToValue() const { return SPtrValue{nullptr}; }
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<bool> : public IPrimitive {
                bool _value;

            public:
                Primitive(bool value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateBoolean(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<float> : public IPrimitive {
                float _value;

            public:
                Primitive(float value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateFloat(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<double> : public IPrimitive {
                double _value;

            public:
                Primitive(double value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateDouble(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<int16> : public IPrimitive {
                int16 _value;

            public:
                Primitive(int16 value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateInt16(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<int32> : public IPrimitive {
                int32 _value;

            public:
                Primitive(int32 value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateInt32(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<int64> : public IPrimitive {
                int64 _value;

            public:
                Primitive(int64 value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateInt64(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<uint16> : public IPrimitive {
                uint16 _value;

            public:
                Primitive(uint16 value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateUInt16(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<uint32> : public IPrimitive {
                uint32 _value;

            public:
                Primitive(uint32 value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateUInt32(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };

            template<>
            class Primitive<uint64> : public IPrimitive {
                uint64 _value;

            public:
                Primitive(uint64 value) : _value{value} { };
                SPtrValue ToValue() const { return ValueFactory::CreateUInt64(_value); };
                SPtrValue operator()() const { return ToValue(); }
            };
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_DATA_PRIMITIVE_H
