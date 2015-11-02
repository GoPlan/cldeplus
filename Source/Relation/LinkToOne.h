//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLDEPLUS_RELATION_LINKTOONE_H
#define CLDEPLUS_RELATION_LINKTOONE_H

#include "../Foundation/EntityQuery.h"
#include "Link.h"

namespace CLDEPlus {
    namespace Relation {

        class LinkToOne : public Link {

        public:
            LinkToOne(Foundation::SPtrEntityQuery const &entityQuery,
                      Foundation::Query::SPtrCriteria const &criteria)
                    : Link{entityQuery, criteria} { }

            LinkToOne(const LinkToOne &) = default;
            LinkToOne(LinkToOne &&) = default;
            LinkToOne &operator=(const LinkToOne &) = default;
            LinkToOne &operator=(LinkToOne &&) = default;
            ~LinkToOne() = default;

            // Locals
            virtual Foundation::SPtrEntityProxy Refer();
        };

        using SPtrLinkToOne = shared_ptr<LinkToOne>;
        SPtrLinkToOne CreateLinkToOne(Foundation::SPtrEntityQuery &entityQuery,
                                      Foundation::Query::SPtrCriteria &criteria);
    }
}


#endif //CLDEPLUS_RELATION_LINKTOONE_H
