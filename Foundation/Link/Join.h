//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_LINK_JOIN_H
#define CLOUD_E_PLUS_FOUNDATION_LINK_JOIN_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Query/Criteria.h>

namespace Cloude {
    namespace Foundation {
        namespace Link {

            class Join {

            public:
                Join(const Join &) = default;
                Join(Join &&) = default;
                Join &operator=(const Join &) = default;
                Join &operator=(Join &&) = default;

                static SPtrProxyVector InnerJoin(SPtrEntityLink &sptrLink, Query::SPtrCriteria &sptrCriteria);
                static SPtrProxyVector LeftJoin(SPtrEntityLink &sptrLink, Query::SPtrCriteria &sptrCriteria);
                static SPtrProxyVector RightJoin(SPtrEntityLink &sptrLink, Query::SPtrCriteria &sptrCriteria);
                static SPtrProxyVector CrossJoin(SPtrEntityLink &sptrLink, Query::SPtrCriteria &sptrCriteria);

            protected:
                Join() = default;
                virtual ~Join() = default;

            };
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_LINK_JOIN_H
