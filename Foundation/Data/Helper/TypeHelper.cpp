//
// Created by LE, Duc Anh on 7/1/15.
//

#include "TypeHelper.h"

namespace Cloude {
    namespace Foundation {
        namespace Data {
            namespace Helper {

                std::string TypeHelper::CopyCategoryToString(const ValueCategory &category) {

                    std::string result;

                    switch (category) {
                        case ValueCategory::Numeric:
                            result = "Numeric";
                            break;
                        case ValueCategory::CharacterBased:
                            result = "CharacterBased";
                            break;
                        case ValueCategory::UserDefined:
                            result = "UserDefined";
                            break;
                        case ValueCategory::Mathematic:
                            result = "Mathematic";
                            break;
                        case ValueCategory::DateTime:
                            result = "DateTime";
                            break;
                    }

                    return result;
                }

                std::string TypeHelper::CopyValueTypeToString(const ValueType &type) {

                    std::string result;

                    switch (type) {
                        case ValueType::Blob:
                            result = "Blob";
                            break;
                        case ValueType::Boolean:
                            result = "Boolean";
                            break;
                        case ValueType::Byte:
                            result = "Byte";
                            break;
                        case ValueType::Int16:
                            result = "Int16";
                            break;
                        case ValueType::Int32:
                            result = "Int32";
                            break;
                        case ValueType::Int64:
                            result = "Int64";
                            break;
                        case ValueType::UInt16:
                            result = "UInt16";
                            break;
                        case ValueType::UInt32:
                            result = "UInt32";
                            break;
                        case ValueType::UInt64:
                            result = "UInt64";
                            break;
                        case ValueType::Double:
                            result = "Double";
                            break;
                        case ValueType::Float:
                            result = "Float";
                            break;
                        case ValueType::String:
                            result = "String";
                            break;
                        case ValueType::VarChar:
                            result = "VarChar";
                            break;
                        case ValueType::Text:
                            result = "Text";
                            break;
                        case ValueType::Currency:
                            result = "Currency";
                            break;
                        case ValueType::Date:
                            result = "Date";
                            break;
                        case ValueType::Time:
                            result = "Time";
                            break;
                        case ValueType::DateTime:
                            result = "DateTime";
                            break;
                        case ValueType::Point:
                            result = "Point";
                            break;
                        case ValueType::Matrix:
                            result = "Matrix";
                            break;
                    }

                    return result;
                }
            }
        }
    }
}


