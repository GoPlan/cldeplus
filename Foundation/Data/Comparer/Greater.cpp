//
// Created by LE, Duc Anh on 6/26/15.
//

#include <Foundation/Data/Type/String.h>
#include <Foundation/Data/Type/VarChar.h>
#include <Foundation/Data/Helper/TypeHelper.h>
#include "Greater.h"

namespace Cloude {
    namespace Foundation {

        bool Data::Comparer::Greater::operator()(const Data::SPtrValue &lhs,
                                                 const Data::SPtrValue &rhs) const {

            if (lhs->getDataType() != rhs->getDataType() || lhs->getCategory() != rhs->getCategory()) {
                std::string lhsType = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                std::string rhsType = Data::Helper::TypeHelper::CopyValueTypeToString(rhs->getDataType());
                std::string msg{lhsType + " has different type/category with " + rhsType};
                throw Exception::cldeNonSupportedDataTypeException{msg};
            }

            switch (lhs->getCategory()) {
                case Data::ValueCategory::Undefined: {
                    std::string msg{"Undefined category is not supported by the comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
                case Data::ValueCategory::Numeric: {
                    return CompareNumeric(lhs, rhs);
                }
                case Data::ValueCategory::CharacterBased: {
                    return CompareCharacterBased(lhs, rhs);
                }
                case Data::ValueCategory::DateTime: {
                    return CompareDateTime(lhs, rhs);
                }
                case Data::ValueCategory::Mathematic: {
                    return CompareMathematic(lhs, rhs);
                }
                case Data::ValueCategory::UserDefined: {
                    std::string msg{"UserDefined category is not supported by the comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
            }
        }

        bool Data::Comparer::Greater::CompareNumeric(
                const Data::SPtrValue &lhs, const Data::SPtrValue &rhs) const {

            switch (lhs->getDataType()) {
                case ValueType::Boolean: {
                    auto ptrLhsTmp = reinterpret_cast<bool *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<bool *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::Byte: {
                    auto ptrLhsTmp = reinterpret_cast<char *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<char *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::Int16: {
                    auto ptrLhsTmp = reinterpret_cast<int16_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int16_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::Int32: {
                    auto ptrLhsTmp = reinterpret_cast<int32_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int32_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::Int64: {
                    auto ptrLhsTmp = reinterpret_cast<int64_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int64_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::UInt16: {
                    auto ptrLhsTmp = reinterpret_cast<uint16_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint16_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::UInt32: {
                    auto ptrLhsTmp = reinterpret_cast<uint32_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint32_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::UInt64: {
                    auto ptrLhsTmp = reinterpret_cast<uint64_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint64_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::Double: {
                    auto ptrLhsTmp = reinterpret_cast<double *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<double *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::Float: {
                    auto ptrLhsTmp = reinterpret_cast<float *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<float *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp > *ptrRhsTmp;
                }
                case ValueType::Currency: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the numeric comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
                default: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the numeric comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
            }
        }

        bool Data::Comparer::Greater::CompareCharacterBased(
                const Data::SPtrValue &lhs, const Data::SPtrValue &rhs) const {

            switch (lhs->getDataType()) {
                case ValueType::String: {

                    auto ptrLhsTmp = dynamic_cast<Data::Type::String *>(lhs.get());
                    auto ptrRhsTmp = dynamic_cast<Data::Type::String *>(lhs.get());

                    return strcmp(((const std::string *) ptrLhsTmp->RawPointerToValueBuffer())->c_str(),
                                  ((const std::string *) ptrRhsTmp->RawPointerToValueBuffer())->c_str()) > 0;
                }
                case ValueType::VarChar: {

                    auto ptrLhsTmp = dynamic_cast<Data::Type::VarChar *>(lhs.get());
                    auto ptrRhsTmp = dynamic_cast<Data::Type::VarChar *>(lhs.get());

                    return strcmp((const char *) ptrLhsTmp->RawPointerToValueBuffer(),
                                  (const char *) ptrRhsTmp->RawPointerToValueBuffer()) > 0;
                }
                case ValueType::Text: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the character based comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
                default: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the character based comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
            }
        }

        bool Data::Comparer::Greater::CompareDateTime(
                const Data::SPtrValue &lhs, const Data::SPtrValue &rhs) const {
            return false;
        }

        bool Data::Comparer::Greater::CompareMathematic(
                const Data::SPtrValue &lhs, const Data::SPtrValue &rhs) const {
            return false;
        }
    }
}


