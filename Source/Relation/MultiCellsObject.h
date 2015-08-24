//
// Created by LE, Duc Anh on 7/18/15.
//

#ifndef CLOUD_E_PLUS_RELATION_MULTICELLSOBJECT_H
#define CLOUD_E_PLUS_RELATION_MULTICELLSOBJECT_H

#include "LinkToOne.h"

namespace Cloude {
    namespace Relation {

        class MultiCellsObject : LinkToOne {

            Foundation::SPtrColumnVector _columns{};

        public:
            MultiCellsObject(const Foundation::SPtrEntityQuery &entityQuery,
                             const Foundation::Query::SPtrCriteria &criteria)
                    : LinkToOne{entityQuery, criteria} { }

            MultiCellsObject(const Foundation::SPtrEntityQuery &entityQuery,
                             const Foundation::Query::SPtrCriteria &criteria,
                             const std::initializer_list<Foundation::SPtrColumn> &columns)
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

        using SPtrMultiCellsObj = std::shared_ptr<MultiCellsObject>;
        SPtrMultiCellsObj CreateMultiCellsObj(const Foundation::SPtrEntityQuery &entityQuery,
                                              const Foundation::Query::SPtrCriteria &criteria,
                                              const std::initializer_list<Foundation::SPtrColumn> &columns);
    }
}


#endif //CLOUD_E_PLUS_RELATION_MULTICELLSOBJECT_H