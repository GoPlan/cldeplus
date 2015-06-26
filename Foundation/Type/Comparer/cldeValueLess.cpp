//
// Created by LE, Duc Anh on 6/26/15.
//

#include <Foundation/Type/Implementation/cldeString.h>
#include <Foundation/Type/Implementation/cldeVarChar.h>
#include "cldeValueLess.h"

namespace Cloude {
    namespace Foundation {

        bool Type::Comparer::cldeValueLess::operator()(const Type::SPtrValue &lhs, const Type::SPtrValue &rhs) const {

            if (lhs->getDataType() != rhs->getDataType() || lhs->getCategory() != rhs->getCategory()) {
                std::string lhsType = Type::cldeType::CopyToString(lhs->getDataType());
                std::string rhsType = Type::cldeType::CopyToString(rhs->getDataType());
                std::string msg{lhsType + " has different type/category with " + rhsType};
                throw Exception::cldeNonSupportedDataTypeException{msg};
            }

            switch (lhs->getCategory()) {
                case Type::cldeType::cldeValueCategory::Undefined: {
                    std::string msg{"Undefined category is not supported by the comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
                case Type::cldeType::cldeValueCategory::Numeric: {
                    return CompareNumeric(lhs, rhs);
                }
                case Type::cldeType::cldeValueCategory::CharacterBased: {
                    return CompareCharacterBased(lhs, rhs);
                }
                case Type::cldeType::cldeValueCategory::DateTime: {
                    return CompareDateTime(lhs, rhs);
                }
                case Type::cldeType::cldeValueCategory::Mathematic: {
                    return CompareMathematic(lhs, rhs);
                }
                case Type::cldeType::cldeValueCategory::UserDefined: {
                    std::string msg{"UserDefined category is not supported by the comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
            }
        }

        bool Type::Comparer::cldeValueLess::CompareNumeric(const Type::SPtrValue &lhs,
                                                           const Type::SPtrValue &rhs) const {

            switch (lhs->getDataType()) {
                case cldeValueType::Boolean: {
                    auto ptrLhsTmp = reinterpret_cast<bool *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<bool *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::Byte: {
                    auto ptrLhsTmp = reinterpret_cast<char *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<char *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::Int16: {
                    auto ptrLhsTmp = reinterpret_cast<int16_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int16_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::Int32: {
                    auto ptrLhsTmp = reinterpret_cast<int32_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int32_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::Int64: {
                    auto ptrLhsTmp = reinterpret_cast<int64_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int64_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::UInt16: {
                    auto ptrLhsTmp = reinterpret_cast<uint16_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint16_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::UInt32: {
                    auto ptrLhsTmp = reinterpret_cast<uint32_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint32_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::UInt64: {
                    auto ptrLhsTmp = reinterpret_cast<uint64_t *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint64_t *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::Double: {
                    auto ptrLhsTmp = reinterpret_cast<double *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<double *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::Float: {
                    auto ptrLhsTmp = reinterpret_cast<float *>(lhs->RawPointerToValueBuffer());
                    auto ptrRhsTmp = reinterpret_cast<float *>(rhs->RawPointerToValueBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case cldeValueType::Currency: {
                    std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the numeric comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
                default: {
                    std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the numeric comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
            }
        }

        bool Type::Comparer::cldeValueLess::CompareCharacterBased(const Type::SPtrValue &lhs,
                                                                  const Type::SPtrValue &rhs) const {
            switch (lhs->getDataType()) {
                case cldeValueType::String: {
                    auto ptrLhsTmp = dynamic_cast<const Type::Implementation::cldeString *>(lhs.get());
                    auto ptrRhsTmp = dynamic_cast<const Type::Implementation::cldeString *>(lhs.get());
                    return strcmp(ptrLhsTmp->ToCString(), ptrRhsTmp->ToCString()) < 0;
                }
                case cldeValueType::VarChar: {
                    auto ptrLhsTmp = dynamic_cast<const Type::Implementation::cldeVarChar *>(lhs.get());
                    auto ptrRhsTmp = dynamic_cast<const Type::Implementation::cldeVarChar *>(lhs.get());
                    return strcmp(ptrLhsTmp->ToCString(), ptrRhsTmp->ToCString()) < 0;
                }
                case cldeValueType::Text: {
                    std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the character based comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
                default: {
                    std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the character based comparer"};
                    throw Exception::cldeNonSupportedDataTypeException{msg};
                }
            }
        }

        bool Type::Comparer::cldeValueLess::CompareDateTime(const Type::SPtrValue &lhs,
                                                            const Type::SPtrValue &rhs) const {
            return false;
        }

        bool Type::Comparer::cldeValueLess::CompareMathematic(const Type::SPtrValue &lhs,
                                                              const Type::SPtrValue &rhs) const {
            return false;
        }
    }
}


