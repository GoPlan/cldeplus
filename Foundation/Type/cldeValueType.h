//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_CLDEVALUETYPE_H
#define CLOUD_E_CPLUS_CLDEVALUETYPE_H

namespace Cloude {
    namespace Foundation {
        namespace Type {

            enum class cldeValueCategory {
                Undefined,
                Numeric,
                CharacterBased,
                UserDefined,
            };

            enum class cldeValueType {
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
                Decimal,
                Numeric,
                String,
                Varchar,
                Text,
                Currency,
                Date,
                Time,
                Timestamp,
                Interval,
                Point,
                Matrix
            };

        }
    }
}

#endif //CLOUD_E_CPLUS_CLDEVALUETYPE_H
