//
// Created by LE, Duc Anh on 7/2/15.
//

#include <Foundation/Data/Helper/TypeHelper.h>
#include <Segmentation/Exception/TransformationException.h>
#include "VarCharConverter.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            Foundation::Data::SPtrValue Converter::VarCharConverter::Convert(
                    const Cloude::Foundation::SPtrColumn &column,
                    const Cloude::Foundation::Data::SPtrValue &value) const {

                std::string type{Foundation::Data::Helper::TypeHelper::CopyToString(column->getDataType())};
                std::string msg{"This converter can not convert VarCharConverter into " + type};
                throw Segmentation::Exception::TransformationException{msg};
            }
        }
    }
}

