//
// Created by LE, Duc Anh on 6/30/15.
//

#include <Foundation/Data/Helper/TypeHelper.h>
#include <Segmentation/Exception/TransformationException.h>
#include "TypeConverter.h"

namespace Cloude {
    namespace Segmentation {

        Foundation::Data::SPtrValue Transformation::TypeConverter::Convert(Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value) const {

            if (dataType == value->getDataType()) {
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
                default: {
                    std::string type{Foundation::Data::Helper::TypeHelper::CopyToString(value->getDataType())};
                    std::string msg{type + " converting is not supported"};
                    throw Segmentation::Exception::TransformationException{msg};
                }
            }

            return value;
        }
    }
}
