//
// Created by LE, Duc Anh on 6/30/15.
//

#include "TypeConverter.h"

namespace Cloude {
    namespace Segmentation {

        Foundation::Type::SPtrValue Transformation::TypeConverter::Convert(const Foundation::SPtrColumn &column,
                                                                           const Foundation::Type::SPtrValue &value) {

            if (column->getDataType() == value->getDataType()) {
                return value;
            }

            switch (column->getDataType()) {
                case Foundation::Type::cldeType::cldeValueType::Boolean:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Byte:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Int16:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Int32:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Int64:
                    break;
                case Foundation::Type::cldeType::cldeValueType::UInt16:
                    break;
                case Foundation::Type::cldeType::cldeValueType::UInt32:
                    break;
                case Foundation::Type::cldeType::cldeValueType::UInt64:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Double:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Float:
                    break;
                case Foundation::Type::cldeType::cldeValueType::String:
                    break;
                case Foundation::Type::cldeType::cldeValueType::VarChar:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Text:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Currency:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Date:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Time:
                    break;
                case Foundation::Type::cldeType::cldeValueType::DateTime:
                    break;
                case Foundation::Type::cldeType::cldeValueType::TimeStamp:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Point:
                    break;
                case Foundation::Type::cldeType::cldeValueType::Matrix:
                    break;
            }

            return value;
        }
    }
}
