//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUETYPE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUETYPE_H

#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Data {

            enum class ValueCategory {
                Undefined,
                Numeric,
                DateTime,
                Mathematic,
                CharacterBased,
                UserDefined,
            };

            enum class ValueType {
                Boolean,
                Byte,
                Int16,
                Int32,
                Int64,
                UInt16,
                UInt32,
                UInt64,
                Double,
                Float,
                String,
                VarChar,
                Text,
                Currency,
                Date,
                Time,
                DateTime,
                TimeStamp,
                Point,
                Matrix
            };

            using ValueType = Data::ValueType;
            using ValueCategory = Data::ValueCategory;
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUETYPE_H
