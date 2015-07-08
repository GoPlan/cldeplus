//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLOUD_E_PLUS_LINKTOONE_H
#define CLOUD_E_PLUS_LINKTOONE_H

#include <Foundation/EntityProxy.h>
#include "Link.h"

namespace Cloude {
    namespace Relation {

        class LinkToOne : public Link {

        public:
            LinkToOne(const Foundation::SPtrEntityQuery &entityQuery, const Foundation::Query::SPtrCriteria &criteria)
                    : Link{entityQuery, criteria} { }

            LinkToOne(const LinkToOne &) = default;
            LinkToOne(LinkToOne &&) = default;
            LinkToOne &operator=(const LinkToOne &) = default;
            LinkToOne &operator=(LinkToOne &&) = default;
            ~LinkToOne() = default;

            // Locals
            Foundation::SPtrEntityProxy Call();
        };
    }
}


#endif //CLOUD_E_PLUS_LINKTOONE_H
