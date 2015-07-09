//
// Created by LE, Duc Anh on 7/2/15.
//

#include <Foundation/Data/Helper/TypeHelper.h>
#include <Segmentation/Exception/TransformationException.h>
#include <Foundation/Data/ValueFactory.h>
#include "StringCaster.h"

namespace Cloude {
    namespace Segmentation {
        namespace Transformation {
            Foundation::Data::SPtrValue Caster::StringCaster::Cast(
                    Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value) const {

                std::string type{Foundation::Data::Helper::TypeHelper::CopyToString(dataType)};
                std::string msg{"This converter can not convert StringCaster into " + type};
                throw Segmentation::Exception::TransformationException{msg};
            }
        }
    }
}

