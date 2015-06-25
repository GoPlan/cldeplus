//
// Created by LE, Duc Anh on 6/25/15.
//

#ifndef CLOUD_E_PLUS_CLDEVALUECOMPARER_H
#define CLOUD_E_PLUS_CLDEVALUECOMPARER_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Exception/cldeNonSupportedDataTypeException.h>

namespace Cloude {
    namespace Foundation {
        namespace Type {
            namespace Comparer {

                enum class ValueComparingResult {
                    LhsValueIsGreater,
                    RhsValueIsGreater,
                    Equal
                };

                struct cldeValueComparer {

                    static ValueComparingResult Compare(const SPtrValue &lhs, const SPtrValue &rhs) {

                        if (lhs->getDataType() != rhs->getDataType() ||
                            lhs->getCategory() != rhs->getCategory()) {
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
                                return CompareNumericType(lhs, rhs);
                            }
                            case Type::cldeType::cldeValueCategory::CharacterBased: {
                                return CompareCharacterBasedType(lhs, rhs);
                            }
                            case Type::cldeType::cldeValueCategory::DateTime: {
                                return CompareDateTimeType(lhs, rhs);
                            }
                            case Type::cldeType::cldeValueCategory::Mathematic: {
                                return CompareMathematicType(lhs, rhs);
                            }
                            case Type::cldeType::cldeValueCategory::UserDefined: {
                                std::string msg{"UserDefined category is not supported by the comparer"};
                                throw Exception::cldeNonSupportedDataTypeException{msg};
                            }
                        }
                    }

                    inline static ValueComparingResult CompareNumericType(const SPtrValue &lhs,
                                                                          const SPtrValue &rhs) {

                        switch (lhs->getDataType()) {
                            case cldeValueType::Boolean:
                                break;
                            case cldeValueType::Byte:
                                break;
                            case cldeValueType::Int16:
                                break;
                            case cldeValueType::Int32:
                                break;
                            case cldeValueType::Int64:
                                break;
                            case cldeValueType::UInt16:
                                break;
                            case cldeValueType::UInt32:
                                break;
                            case cldeValueType::UInt64:
                                break;
                            case cldeValueType::Double:
                                break;
                            case cldeValueType::Float:
                                break;
                            case cldeValueType::Currency:
                                break;
                            default:
                                std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                                std::string msg{type + " is not supported by the numeric comparer"};
                                throw Exception::cldeNonSupportedDataTypeException{msg};
                        }

                        return ValueComparingResult::Equal;
                    }

                    inline static ValueComparingResult CompareCharacterBasedType(const SPtrValue &lhs,
                                                                                 const SPtrValue &rhs) {

                        switch (lhs->getDataType()) {
                            case cldeValueType::Date:
                                break;
                            case cldeValueType::Time:
                                break;
                            case cldeValueType::DateTime:
                                break;
                            case cldeValueType::TimeStamp:
                                break;
                            default:
                                std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                                std::string msg{type + " is not supported by the character based comparer"};
                                throw Exception::cldeNonSupportedDataTypeException{msg};
                        }

                        return ValueComparingResult::Equal;
                    }

                    inline static ValueComparingResult CompareDateTimeType(const SPtrValue &lhs,
                                                                           const SPtrValue &rhs) {

                        switch (lhs->getDataType()) {
                            case cldeValueType::Date:
                                break;
                            case cldeValueType::Time:
                                break;
                            case cldeValueType::DateTime:
                                break;
                            case cldeValueType::TimeStamp:
                                break;
                            default:
                                std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                                std::string msg{type + " is not supported by the date & time comparer"};
                                throw Exception::cldeNonSupportedDataTypeException{msg};
                        }

                        return ValueComparingResult::Equal;
                    }

                    inline static ValueComparingResult CompareMathematicType(const SPtrValue &lhs,
                                                                             const SPtrValue &rhs) {

                        switch (lhs->getDataType()) {
                            case cldeValueType::Point:
                                break;
                            case cldeValueType::Matrix:
                                break;
                            default:
                                std::string type = Type::cldeType::CopyToString(lhs->getDataType());
                                std::string msg{type + " is not supported by the mathematic comparer"};
                                throw Exception::cldeNonSupportedDataTypeException{msg};
                        }

                        return ValueComparingResult::Equal;
                    }
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_CLDEVALUECOMPARER_H
