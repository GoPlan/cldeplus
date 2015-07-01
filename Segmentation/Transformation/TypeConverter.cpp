//
// Created by LE, Duc Anh on 6/30/15.
//

#include "TypeConverter.h"

namespace Cloude {
    namespace Segmentation {

        Foundation::Data::SPtrValue Transformation::TypeConverter::Convert(const Foundation::SPtrColumn &column,
                                                                           const Foundation::Data::SPtrValue &value) {

            if (column->getDataType() == value->getDataType()) {
                return value;
            }

            switch (value->getDataType()) {
                case Foundation::Data::ValueType::Boolean:
                    break;
                case Foundation::Data::ValueType::Byte:
                    break;
                case Foundation::Data::ValueType::Int16:
                    break;
                case Foundation::Data::ValueType::Int32:
                    break;
                case Foundation::Data::ValueType::Int64:
                    break;
                case Foundation::Data::ValueType::UInt16:
                    break;
                case Foundation::Data::ValueType::UInt32:
                    break;
                case Foundation::Data::ValueType::UInt64:
                    break;
                case Foundation::Data::ValueType::Double:
                    break;
                case Foundation::Data::ValueType::Float:
                    break;
                case Foundation::Data::ValueType::String:
                    break;
                case Foundation::Data::ValueType::VarChar:
                    break;
                case Foundation::Data::ValueType::Text:
                    break;
                case Foundation::Data::ValueType::Currency:
                    break;
                case Foundation::Data::ValueType::Date:
                    break;
                case Foundation::Data::ValueType::Time:
                    break;
                case Foundation::Data::ValueType::DateTime:
                    break;
                case Foundation::Data::ValueType::TimeStamp:
                    break;
                case Foundation::Data::ValueType::Point:
                    break;
                case Foundation::Data::ValueType::Matrix:
                    break;
            }

            return value;
        }
    }
}
