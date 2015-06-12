//
// Created by LE, Duc Anh on 6/9/15.
//

#ifndef CLOUD_E_CPLUS_FOUNDATION_QUERY_ENUMERATION_COMPARATIVETYPE_H
#define CLOUD_E_CPLUS_FOUNDATION_QUERY_ENUMERATION_COMPARATIVETYPE_H

namespace Cloude {
    namespace Foundation {
        namespace Query {
            namespace Enumeration {
                enum class ComparativeType {
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


#endif //CLOUD_E_CPLUS_FOUNDATION_QUERY_ENUMERATION_COMPARATIVETYPE_H
