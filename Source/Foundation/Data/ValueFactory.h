//
// Created by LE, Duc Anh on 6/10/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEFACTORY_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEFACTORY_H

#include "Value.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            struct ValueFactory {

                // Numeric
                static SPtrValue CreateByte(char value);
                static SPtrValue CreateBoolean(bool value);
                static SPtrValue CreateFloat(float value);
                static SPtrValue CreateDouble(double value);
                static SPtrValue CreateInt(int value);
                static SPtrValue CreateInt16(int16_t value);
                static SPtrValue CreateInt32(int32_t value);
                static SPtrValue CreateInt64(int64_t value);
                static SPtrValue CreateUInt(unsigned int value);
                static SPtrValue CreateUInt16(uint16_t value);
                static SPtrValue CreateUInt32(uint32_t value);
                static SPtrValue CreateUInt64(uint64_t value);

                // Character
                static SPtrValue CreateVarChar(char const *value);
                static SPtrValue CreateVarChar(string const &value);
                static SPtrValue CreateVarChar(unsigned long length);
                static SPtrValue CreateText(string const &value);
                static SPtrValue CreateText(unsigned long length);

                // DateTime
                static SPtrValue CreateDate();
                static SPtrValue CreateDate(int year, int month, int day);
                static SPtrValue CreateTime();
                static SPtrValue CreateTime(int hour, int minute, int second);
                static SPtrValue CreateTime(int hour, int minute, int second, int milliseconds);
                static SPtrValue CreateTime(int hour, int minute, int second, int milliseconds, int offset);
                static SPtrValue CreateDateTime();
                static SPtrValue CreateDateTime(int year, int month, int day);
                static SPtrValue CreateDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond = 0, int offset = 0);
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_VALUEFACTORY_H
