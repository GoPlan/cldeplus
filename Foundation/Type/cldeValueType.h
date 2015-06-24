//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUETYPE_H
#define CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUETYPE_H

#include <string>

namespace Cloude {
    namespace Foundation {
        namespace Type {

            struct cldeType {

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

                static std::string CopyToString(const cldeValueCategory &category);
                static std::string CopyToString(const cldeValueType &type);

            };

            using cldeValueType = cldeType::cldeValueType;
            using cldeValueCategory = cldeType::cldeValueCategory;
        }
    }
}

#endif //CLOUD_E_CPLUS_FOUNDATION_TYPE_CLDEVALUETYPE_H
