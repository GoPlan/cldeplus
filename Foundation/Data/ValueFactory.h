//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEFACTORY_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEFACTORY_H

#include <memory>
#include "Value.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {

            class ValueFactory {

            public:
                ValueFactory() = delete;
                ValueFactory(const ValueFactory &) = delete;
                ValueFactory(ValueFactory &&) = delete;
                ValueFactory &operator=(const ValueFactory &) = delete;
                ValueFactory &operator=(ValueFactory &&) = delete;
                ~ValueFactory() = delete;

                static SPtrValue CreateFloat(float value);
                static SPtrValue CreateDouble(double value);
                static SPtrValue CreateInt16(int16_t value);
                static SPtrValue CreateInt32(int32_t value);
                static SPtrValue CreateInt64(int64_t value);
                static SPtrValue CreateUInt16(uint16_t value);
                static SPtrValue CreateUInt32(uint32_t value);
                static SPtrValue CreateUInt64(uint64_t value);
                static SPtrValue CreateString(const char *value);
                static SPtrValue CreateVarChar(const char *value);
                static SPtrValue CreateVarChar(const std::string &value);
                static SPtrValue CreateVarChar(unsigned long length);
                static SPtrValue CreateByte(char value);
                static SPtrValue CreateBoolean(bool value);
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEFACTORY_H
