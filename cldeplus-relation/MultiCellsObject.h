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

#ifndef CLDEPLUS_RELATION_MULTICELLSOBJECT_H
#define CLDEPLUS_RELATION_MULTICELLSOBJECT_H

#include "LinkToOne.h"

namespace CLDEPlus {
    namespace Relation {

        class MultiCellsObject : LinkToOne {

            Foundation::SPtrColumnVector _columns{};

        public:
            MultiCellsObject(Foundation::SPtrEntityQuery const &entityQuery,
                             Foundation::Query::SPtrCriteria const &criteria)
                    : LinkToOne{entityQuery, criteria} { }

            MultiCellsObject(Foundation::SPtrEntityQuery const &entityQuery,
                             Foundation::Query::SPtrCriteria const &criteria,
                             std::initializer_list<Foundation::SPtrColumn> const &columns)
                    : LinkToOne{entityQuery, criteria}, _columns{columns} { }

            MultiCellsObject(MultiCellsObject const &) = default;
            MultiCellsObject(MultiCellsObject &&) = default;
            MultiCellsObject &operator=(MultiCellsObject const &) = default;
            MultiCellsObject &operator=(MultiCellsObject &&) = default;
            ~MultiCellsObject() = default;

            // Accessors & Mutators
            Foundation::SPtrColumnVector &Columns() { return _columns; };

            // Locals
            Foundation::SPtrEntityProxy Refer() override;
        };

        using SPtrMultiCellsObj = shared_ptr<MultiCellsObject>;

        SPtrMultiCellsObj CreateMultiCellsObj(Foundation::SPtrEntityQuery &entityQuery,
                                              Foundation::Query::SPtrCriteria &criteria,
                                              std::initializer_list<Foundation::SPtrColumn> &columns);
    }
}


#endif //CLDEPLUS_RELATION_MULTICELLSOBJECT_H
