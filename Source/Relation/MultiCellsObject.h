//
// Created by LE, Duc Anh on 7/18/15.
//

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
                    : LinkToOne{entityQuery, criteria},
                      _columns{columns} { }

            MultiCellsObject(const MultiCellsObject &) = default;
            MultiCellsObject(MultiCellsObject &&) = default;
            MultiCellsObject &operator=(const MultiCellsObject &) = default;
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
