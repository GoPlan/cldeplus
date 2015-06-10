//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_COMPARATORTYPE_H
#define CLOUD_E_CPLUS_COMPARATORTYPE_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Enumeration {
                enum class ComparatorType {
                    And,
                    Or,
                    Equal,
                    NotEqual,
                    Greater,
                    GreaterOrEqual,
                    Lesser,
                    LesserOrEqual,
                    Like,
                    NotLike,
                    IsNull,
                    IsNotNull
                };
            }
        }
    }
}


#endif //CLOUD_E_CPLUS_COMPARATORTYPE_H
