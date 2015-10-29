//
// Created by LE, Duc Anh on 7/8/15.
//

#ifndef CLDEPLUS_RELATION_LINK_H
#define CLDEPLUS_RELATION_LINK_H

#include "../Foundation/EntityQuery.h"

namespace CLDEPlus {
    namespace Relation {

        class Link {

        public:
            Link(const Foundation::SPtrEntityQuery &entityQuery, const Foundation::Query::SPtrCriteria &criteria)
                    : _sptrEntityQuery{entityQuery}, _sptrCriteria{criteria} { };

            Link(const Link &) = default;
            Link(Link &&) = default;
            Link &operator=(const Link &) = default;
            Link &operator=(Link &&) = default;
            virtual ~Link() = default;

            // Accessors
            const Foundation::SPtrEntityQuery &EntityQuery() const { return _sptrEntityQuery; }
            const Foundation::Query::SPtrCriteria &Criteria() const { return _sptrCriteria; }

        protected:
            Foundation::SPtrEntityQuery _sptrEntityQuery;
            Foundation::Query::SPtrCriteria _sptrCriteria;

        };
    }
}


#endif //CLDEPLUS_RELATION_LINK_H
