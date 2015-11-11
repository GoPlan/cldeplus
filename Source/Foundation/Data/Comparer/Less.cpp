/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include "Less.h"
#include "../Helper/TypeHelper.h"
#include "../Type/String.h"
#include "../Type/VarChar.h"
#include "../../Exception/CLDENotImplementedException.h"
#include "../../Exception/CLDENonSupportedDataTypeException.h"
#include "../../Common/IComparable.h"

namespace CLDEPlus {
    namespace Foundation {

        bool Data::Comparer::Less::operator()(const Data::SPtrValue &lhs, const Data::SPtrValue &rhs) const {

            if (lhs->getDataType() != rhs->getDataType() || lhs->getCategory() != rhs->getCategory()) {
                string lhsType = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                string rhsType = Data::Helper::TypeHelper::CopyValueTypeToString(rhs->getDataType());
                string msg{lhsType + " has different type/category with " + rhsType};
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
                    string msg{"UserDefined category is not supported by the comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
                default:
                    return false;
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
                    string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    string msg{type + " is not supported by the numeric comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
                default: {
                    string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    string msg{type + " is not supported by the numeric comparer"};
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
                    string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    string msg{type + " is not supported by the character based comparer"};
                    throw Exception::CLDENonSupportedDataTypeException{msg};
                }
                default: {
                    string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    string msg{type + " is not supported by the character based comparer"};
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
                    string type = Data::Helper::TypeHelper::CopyValueTypeToString(lhs->getDataType());
                    string msg{type + " is not supported by the date&time based comparer"};
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


