/*

Copyright 2015 LE, Duc-Anh

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

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
