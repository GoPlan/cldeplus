//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLDEPLUS_RELATION_LINKTOMANY_H
#define CLDEPLUS_RELATION_LINKTOMANY_H

#include "../Foundation/EntityProxy.h"
#include "Link.h"

namespace CLDEPlus {
    namespace Relation {

        class LinkToMany : public Link {

        public:
            LinkToMany(const Foundation::SPtrEntityQuery &entityQuery, const Foundation::Query::SPtrCriteria &criteria)
                    : Link{entityQuery, criteria} { }

            LinkToMany(const LinkToMany &) = default;
            LinkToMany(LinkToMany &&) = default;
            LinkToMany &operator=(const LinkToMany &) = default;
            LinkToMany &operator=(LinkToMany &&) = default;
            ~LinkToMany() = default;

            // Locals
            Foundation::SPtrEntityProxyVector Refer();
        };

        using SPtrLinkToMany = shared_ptr<LinkToMany>;
        SPtrLinkToMany CreateLinkToMany(const Foundation::SPtrEntityQuery &entityQuery,
                                        const Foundation::Query::SPtrCriteria &criteria);
    }
}


#endif //CLDEPLUS_RELATION_LINKTOMANY_H
