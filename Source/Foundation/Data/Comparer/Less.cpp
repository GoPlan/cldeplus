//
// Created by LE, Duc Anh on 6/26/15.
//

#include <Foundation/Data/Type/String.h>
#include <Foundation/Data/Type/VarChar.h>
#include <Foundation/Data/Helper/TypeHelper.h>
#include <Foundation/Common/IComparable.h>
#include "../../Exception/CLDENotImplementedException.h"
#include "../../Exception/CLDENonSupportedDataTypeException.h"
#include "Less.h"

namespace Cloude {
    namespace Foundation {

        bool Data::Comparer::Less::operator()(const Data::SPtrValue &lhs, const Data::SPtrValue &rhs) const {

            if (lhs->getDataType() != rhs->getDataType() || lhs->getCategory() != rhs->getCategory()) {
                std::string lhsType = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                std::string rhsType = Data::Helper::TypeHelper::CopyValueTypeToString(rhs->getDataType());
                std::string msg{lhsType + " has different type/category with " + rhsType};
                throw Exception::CLDENonSupportedDataTypeException{msg};
            }

            switch (lhs->getCategory()) {
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
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
            }
        }

        bool Data::Comparer::Less::CompareNumeric(const Data::SPtrValue &lhs,
                                                  const Data::SPtrValue &rhs) const {

            switch (lhs->getDataType()) {
                case ValueType::Boolean: {
                    auto ptrLhsTmp = reinterpret_cast<bool *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<bool *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::Byte: {
                    auto ptrLhsTmp = reinterpret_cast<char *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<char *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::Int16: {
                    auto ptrLhsTmp = reinterpret_cast<int16_t *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int16_t *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::Int32: {
                    auto ptrLhsTmp = reinterpret_cast<int32_t *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int32_t *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::Int64: {
                    auto ptrLhsTmp = reinterpret_cast<int64_t *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<int64_t *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::UInt16: {
                    auto ptrLhsTmp = reinterpret_cast<uint16_t *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint16_t *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::UInt32: {
                    auto ptrLhsTmp = reinterpret_cast<uint32_t *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint32_t *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::UInt64: {
                    auto ptrLhsTmp = reinterpret_cast<uint64_t *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<uint64_t *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::Double: {
                    auto ptrLhsTmp = reinterpret_cast<double *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<double *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::Float: {
                    auto ptrLhsTmp = reinterpret_cast<float *>(lhs->PointerToBuffer());
                    auto ptrRhsTmp = reinterpret_cast<float *>(rhs->PointerToBuffer());
                    return *ptrLhsTmp < *ptrRhsTmp;
                }
                case ValueType::Currency: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the numeric comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
                default: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the numeric comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
            }
        }

        bool Data::Comparer::Less::CompareCharacterBased(const Data::SPtrValue &lhs,
                                                         const Data::SPtrValue &rhs) const {
            switch (lhs->getDataType()) {
                case ValueType::String: {
                    auto ptrLhsTmp = dynamic_cast<const Data::Type::String *>(lhs.get());
                    auto ptrRhsTmp = dynamic_cast<const Data::Type::String *>(lhs.get());
                    return strcmp(ptrLhsTmp->ToString().c_str(), ptrRhsTmp->ToString().c_str()) < 0;
                }
                case ValueType::VarChar: {
                    auto ptrLhsTmp = dynamic_cast<const Data::Type::VarChar *>(lhs.get());
                    auto ptrRhsTmp = dynamic_cast<const Data::Type::VarChar *>(lhs.get());
                    return strcmp(ptrLhsTmp->ToString().c_str(), ptrRhsTmp->ToString().c_str()) < 0;
                }
                case ValueType::Text: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the character based comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
                default: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the character based comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
            }
        }

        bool Data::Comparer::Less::CompareDateTime(const Data::SPtrValue &lhs,
                                                   const Data::SPtrValue &rhs) const {

            auto &lhsComparable = dynamic_cast<const Common::IComparable &>(*lhs);
            auto &rhsComparable = dynamic_cast<const Common::IComparable &>(*rhs);

            switch (lhs->getDataType()) {
                case ValueType::Date: {
                    return lhsComparable.LessThan(rhsComparable);
                }
                case ValueType::Time: {
                    return lhsComparable.LessThan(rhsComparable);
                }
                case ValueType::DateTime: {
                    return lhsComparable.LessThan(rhsComparable);
                }
                default: {
                    std::string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    std::string msg{type + " is not supported by the date&time based comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
            }
        }

        bool Data::Comparer::Less::CompareMathematic(const Data::SPtrValue &lhs,
                                                     const Data::SPtrValue &rhs) const {
            throw Exception::CLDENotImplementedException{"CompareMathematic"};
        }
    }
}


