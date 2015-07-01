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

namespace Cloude {
    namespace Foundation {
        namespace Data {

            SPtrValue ValueFactory::CreateFloat(float value) {
                auto spValue = std::make_shared<Type::Float>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateDouble(double value) {
                auto spValue = std::make_shared<Type::Double>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateInt16(int16_t value) {
                auto spValue = std::make_shared<Type::Int16>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateInt32(int32_t value) {
                auto spValue = std::make_shared<Type::Int32>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateInt64(int64_t value) {
                auto spValue = std::make_shared<Type::Int64>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateUInt16(uint16_t value) {
                auto spValue = std::make_shared<Type::UInt16>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateUInt32(uint32_t value) {
                auto spValue = std::make_shared<Type::UInt32>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateUInt64(uint64_t value) {
                auto spValue = std::make_shared<Type::UInt64>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateString(const char *value) {
                auto spValue = std::make_shared<Type::String>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateVarChar(const char *value) {
                auto spValue = std::make_shared<Type::VarChar>(value);
                return spValue;
            }

            SPtrValue ValueFactory::CreateVarChar(const std::string &value) {
                auto spValue = std::make_shared<Type::VarChar>(value.c_str());
                return spValue;
            }

            SPtrValue ValueFactory::CreateVarChar(unsigned long length) {
                auto spValue = std::make_shared<Type::VarChar>(length);
                return spValue;
            }
        }
    }
}


