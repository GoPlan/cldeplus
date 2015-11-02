//
// Created by LE, Duc Anh on 6/10/15.
//

#include "ValueFactory.h"

#include "Type/Double.h"
#include "Type/Int16.h"
#include "Type/Int32.h"
#include "Type/Int64.h"
#include "Type/UInt16.h"
#include "Type/UInt32.h"
#include "Type/UInt64.h"
#include "Type/String.h"
#include "Type/VarChar.h"
#include "Type/Byte.h"
#include "Type/Boolean.h"
#include "Type/Text.h"
#include "Type/Date.h"
#include "Type/Time.h"
#include "Type/DateTime.h"
#include "Type/Float.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Data {

            SPtrValue ValueFactory::CreateFloat(float value) {
                return std::make_shared<Type::Float>(value);
            }

            SPtrValue ValueFactory::CreateDouble(double value) {
                return std::make_shared<Type::Double>(value);
            }

            SPtrValue ValueFactory::CreateInt16(int16_t value) {
                return std::make_shared<Type::Int16>(value);
            }

            SPtrValue ValueFactory::CreateInt32(int32_t value) {
                return std::make_shared<Type::Int32>(value);
            }

            SPtrValue ValueFactory::CreateInt64(int64_t value) {
                return std::make_shared<Type::Int64>(value);
            }

            SPtrValue ValueFactory::CreateUInt16(uint16_t value) {
                return std::make_shared<Type::UInt16>(value);
            }

            SPtrValue ValueFactory::CreateUInt32(uint32_t value) {
                return std::make_shared<Type::UInt32>(value);
            }

            SPtrValue ValueFactory::CreateUInt64(uint64_t value) {
                return std::make_shared<Type::UInt64>(value);
            }

            SPtrValue ValueFactory::CreateVarChar(const char *value) {
                return std::make_shared<Type::VarChar>(value);
            }

            SPtrValue ValueFactory::CreateVarChar(const std::string &value) {
                return std::make_shared<Type::VarChar>(value.c_str());
            }

            SPtrValue ValueFactory::CreateVarChar(unsigned long length) {
                return std::make_shared<Type::VarChar>(length);
            }

            SPtrValue ValueFactory::CreateText(const std::string &value) {
                return std::make_shared<Type::Text>(value);
            }

            SPtrValue ValueFactory::CreateText(unsigned long length) {
                return std::make_shared<Type::Text>(length);
            }

            SPtrValue ValueFactory::CreateByte(char value) {
                return std::make_shared<Type::Byte>(value);
            }

            SPtrValue ValueFactory::CreateBoolean(bool value) {
                return std::make_shared<Type::Boolean>(value);
            }

            SPtrValue ValueFactory::CreateDate() {
                return std::make_shared<Type::Date>();
            }

            SPtrValue ValueFactory::CreateDate(int year, int month, int day) {
                return std::make_shared<Type::Date>(year, month, day);
            }

            SPtrValue ValueFactory::CreateTime() {
                return std::make_shared<Type::Time>();
            }

            SPtrValue ValueFactory::CreateTime(int hour, int minute, int second) {
                return std::make_shared<Type::Time>(hour, minute, second);
            }

            SPtrValue ValueFactory::CreateTime(int hour, int minute, int second, int millisecond) {
                return std::make_shared<Type::Time>(hour, minute, second, millisecond);
            }

            SPtrValue ValueFactory::CreateTime(int hour, int minute, int second, int millisecond,
                                               int offset) {
                return std::make_shared<Type::Time>(hour, minute, second, millisecond, offset);
            }

            SPtrValue ValueFactory::CreateDateTime() {
                return std::make_shared<Type::DateTime>();
            }

            SPtrValue ValueFactory::CreateDateTime(int year, int month, int day) {
                return std::make_shared<Type::DateTime>(year, month, day);
            }

            SPtrValue ValueFactory::CreateDateTime(int year, int month, int day,
                                                   int hour, int minute, int second, int millisecond,
                                                   int offset) {
                return std::make_shared<Type::DateTime>(year, month, day, hour, minute, second, millisecond,
                                                        offset);
            }
        }
    }
}


