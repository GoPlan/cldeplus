//
// Created by LE, Duc Anh on 6/9/15.
//

#include "cldeValueType.h"


std::string Cloude::Foundation::Type::cldeType::CopyToString(const cldeType::cldeValueCategory &category) {

    std::string result;

    switch (category) {
        case cldeValueCategory::Undefined:
            result = "Undefined";
            break;
        case cldeValueCategory::Numeric:
            result = "Numeric";
            break;
        case cldeValueCategory::CharacterBased:
            result = "CharacterBased";
            break;
        case cldeValueCategory::UserDefined:
            result = "UserDefined";
            break;
    }

    return result;
}

std::string Cloude::Foundation::Type::cldeType::CopyToString(const cldeType::cldeValueType &type) {

    std::string result;

    switch (type) {
        case cldeValueType::Boolean:
            result = "Boolean";
            break;
        case cldeValueType::Byte:
            result = "Byte";
            break;
        case cldeValueType::Int16:
            result = "Int16";
            break;
        case cldeValueType::Int32:
            result = "Int32";
            break;
        case cldeValueType::Int64:
            result = "Boolean";
            break;
        case cldeValueType::UInt16:
            result = "UInt16";
            break;
        case cldeValueType::UInt32:
            result = "UInt32";
            break;
        case cldeValueType::UInt64:
            result = "UInt64";
            break;
        case cldeValueType::Double:
            result = "Double";
            break;
        case cldeValueType::Float:
            result = "Float";
            break;
        case cldeValueType::Decimal:
            result = "Decimal";
            break;
        case cldeValueType::String:
            result = "String";
            break;
        case cldeValueType::Varchar:
            result = "Varchar";
            break;
        case cldeValueType::Text:
            result = "Text";
            break;
        case cldeValueType::Currency:
            result = "Currency";
            break;
        case cldeValueType::Date:
            result = "Date";
            break;
        case cldeValueType::Time:
            result = "Time";
            break;
        case cldeValueType::DateTime:
            result = "DateTime";
            break;
        case cldeValueType::Timestamp:
            result = "Timestamp";
            break;
        case cldeValueType::Point:
            result = "Point";
            break;
        case cldeValueType::Matrix:
            result = "Matrix";
            break;
    }

    return result;
}
