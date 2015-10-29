//
// Created by LE, Duc Anh on 7/2/15.
//

#include "VarCharCaster.h"
#include "../../../Foundation/Data/Helper/TypeHelper.h"
#include "../../Exception/TransformationException.h"

namespace CLDEPlus {
    namespace Segmentation {
        namespace Transformation {
            Foundation::Data::SPtrValue Caster::VarCharCaster::Cast(
                    Foundation::Data::ValueType dataType, const Foundation::Data::SPtrValue &value) const {
                std::string type{Foundation::Data::Helper::TypeHelper::CopyValueTypeToString(dataType)};
                std::string msg{"This converter can not convert VarCharCaster into " + type};
                throw Segmentation::Exception::TransformationException{msg};
            }
        }
    }
}

