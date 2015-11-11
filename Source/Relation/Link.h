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

#ifndef CLDEPLUS_RELATION_LINK_H
#define CLDEPLUS_RELATION_LINK_H

#include "../Foundation/EntityQuery.h"

namespace CLDEPlus {
    namespace Relation {

        class Link {

        public:
            Link(Foundation::SPtrEntityQuery const &entityQuery,
                 Foundation::Query::SPtrCriteria const &criteria)
                    : _sptrEntityQuery{entityQuery}, _sptrCriteria{criteria} { };

            Link(const Link &) = default;
            Link(Link &&) = default;
            Link &operator=(const Link &) = default;
            Link &operator=(Link &&) = default;
            virtual ~Link() = default;

            // Accessors
            Foundation::SPtrEntityQuery const &EntityQuery() const { return _sptrEntityQuery; }
            Foundation::Query::SPtrCriteria const &Criteria() const { return _sptrCriteria; }

        protected:
            Foundation::SPtrEntityQuery _sptrEntityQuery;
            Foundation::Query::SPtrCriteria _sptrCriteria;

        };
    }
}


#endif //CLDEPLUS_RELATION_LINK_H
