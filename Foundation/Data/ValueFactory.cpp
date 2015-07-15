//
// Created by LE, Duc Anh on 6/10/15.
//

#include "ValueFactory.h"

#include <Foundation/Data/Type/Float.h>
#include <Foundation/Data/Type/Double.h>
#include <Foundation/Data/Type/Int16.h>
#include <Foundation/Data/Type/Int32.h>
#include <Foundation/Data/Type/Int64.h>
#include <Foundation/Data/Type/UInt16.h>
#include <Foundation/Data/Type/UInt32.h>
#include <Foundation/Data/Type/UInt64.h>
#include <Foundation/Data/Type/String.h>
#include <Foundation/Data/Type/VarChar.h>
#include <Foundation/Data/Type/Byte.h>
#include <Foundation/Data/Type/Boolean.h>
#include <Foundation/Data/Type/Text.h>

namespace Cloude {
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

            SPtrValue ValueFactory::CreateString(const char *value) {
                return std::make_shared<Type::String>(value);
            }

            SPtrValue ValueFactory::CreateVarChar(const char *value) {
                return std::make_shared<Type::VarChar>(value);
            }

            SPtrValue ValueFactory::CreateVarChar(const std::string &value) {
                return std::make_shared<Type::VarChar>(value.c_str());
            }

            SPtrValue ValueFactory::CreateText(const std::string &value) {
                return std::make_shared<Type::Text>();
            }

            SPtrValue ValueFactory::CreateVarChar(unsigned long length) {
                return std::make_shared<Type::VarChar>(length);
            }

            SPtrValue ValueFactory::CreateByte(char value) {
                return std::make_shared<Type::Byte>(value);
            }

            SPtrValue ValueFactory::CreateBoolean(bool value) {
                return std::make_shared<Type::Boolean>(value);
            }
        }
    }
}


