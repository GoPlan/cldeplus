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
                return cldeplus_make_shared<Type::Float>(value);
            }

            SPtrValue ValueFactory::CreateDouble(double value) {
                return cldeplus_make_shared<Type::Double>(value);
            }

            SPtrValue ValueFactory::CreateInt(int value) {
                return CreateInt32((int32_t) value);
            }

            SPtrValue ValueFactory::CreateInt16(int16_t value) {
                return cldeplus_make_shared<Type::Int16>(value);
            }

            SPtrValue ValueFactory::CreateInt32(int32_t value) {
                return cldeplus_make_shared<Type::Int32>(value);
            }

            SPtrValue ValueFactory::CreateInt64(int64_t value) {
                return cldeplus_make_shared<Type::Int64>(value);
            }

            SPtrValue ValueFactory::CreateUInt16(uint16_t value) {
                return cldeplus_make_shared<Type::UInt16>(value);
            }

            SPtrValue ValueFactory::CreateUInt(unsigned int value) {
                return CreateUInt32((uint32_t) value);
            }

            SPtrValue ValueFactory::CreateUInt32(uint32_t value) {
                return cldeplus_make_shared<Type::UInt32>(value);
            }

            SPtrValue ValueFactory::CreateUInt64(uint64_t value) {
                return cldeplus_make_shared<Type::UInt64>(value);
            }

            SPtrValue ValueFactory::CreateVarChar(char const *value) {
                return cldeplus_make_shared<Type::VarChar>(value);
            }

            SPtrValue ValueFactory::CreateVarChar(string const &value) {
                return cldeplus_make_shared<Type::VarChar>(value.c_str());
            }

            SPtrValue ValueFactory::CreateVarChar(unsigned long length) {
                return cldeplus_make_shared<Type::VarChar>(length);
            }

            SPtrValue ValueFactory::CreateText(string const &value) {
                return cldeplus_make_shared<Type::Text>(value);
            }

            SPtrValue ValueFactory::CreateText(unsigned long length) {
                return cldeplus_make_shared<Type::Text>(length);
            }

            SPtrValue ValueFactory::CreateByte(char value) {
                return cldeplus_make_shared<Type::Byte>(value);
            }

            SPtrValue ValueFactory::CreateBoolean(bool value) {
                return cldeplus_make_shared<Type::Boolean>(value);
            }

            SPtrValue ValueFactory::CreateDate() {
                return cldeplus_make_shared<Type::Date>();
            }

            SPtrValue ValueFactory::CreateDate(int year, int month, int day) {
                return cldeplus_make_shared<Type::Date>(year, month, day);
            }

            SPtrValue ValueFactory::CreateTime() {
                return cldeplus_make_shared<Type::Time>();
            }

            SPtrValue ValueFactory::CreateTime(int hour, int minute, int second) {
                return cldeplus_make_shared<Type::Time>(hour, minute, second);
            }

            SPtrValue ValueFactory::CreateTime(int hour, int minute, int second, int millisecond) {
                return cldeplus_make_shared<Type::Time>(hour, minute, second, millisecond);
            }

            SPtrValue ValueFactory::CreateTime(int hour, int minute, int second, int millisecond, int offset) {
                return cldeplus_make_shared<Type::Time>(hour, minute, second, millisecond, offset);
            }

            SPtrValue ValueFactory::CreateDateTime() {
                return cldeplus_make_shared<Type::DateTime>();
            }

            SPtrValue ValueFactory::CreateDateTime(int year, int month, int day) {
                return cldeplus_make_shared<Type::DateTime>(year, month, day);
            }

            SPtrValue ValueFactory::CreateDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int offset) {
                return cldeplus_make_shared<Type::DateTime>(year, month, day, hour, minute, second, millisecond, offset);
            }
        }
    }
}


