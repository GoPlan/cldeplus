//
// Created by LE, Duc Anh on 11/9/15.
//

#ifndef CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVETOVALUE_HPP
#define CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVETOVALUE_HPP

#include "../Value.h"
#include "../ValueFactory.h"
#include "../../../Port/Definitions.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {
            namespace Helper {

                template<typename T>
                class Primitive {
                    T _value;

                public:
                    Primitive(T value) : _value{value} { };
                    SPtrValue ToValue() const { return SPtrValue{nullptr}; }
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<bool> {
                    bool _value;

                public:
                    Primitive(bool value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateBoolean(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<float> {
                    float _value;

                public:
                    Primitive(float value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateFloat(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<double> {
                    double _value;

                public:
                    Primitive(double value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateDouble(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<int16> {
                    int16 _value;

                public:
                    Primitive(int16 value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateInt16(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<int32> {
                    int32 _value;

                public:
                    Primitive(int32 value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateInt32(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<int64> {
                    int64 _value;

                public:
                    Primitive(int64 value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateInt64(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<uint16> {
                    uint16 _value;

                public:
                    Primitive(uint16 value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateUInt16(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<uint32> {
                    uint32 _value;

                public:
                    Primitive(uint32 value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateUInt32(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };

                template<>
                class Primitive<uint64> {
                    uint64 _value;

                public:
                    Primitive(uint64 value) : _value{value} { };
                    SPtrValue ToValue() const { return ValueFactory::CreateUInt64(_value); };
                    SPtrValue operator()() const { return ToValue(); }
                };
            }
        }
    }
}

#endif //CLDEPLUS_FOUNDATION_DATA_HELPER_PRIMITIVETOVALUE_HPP
