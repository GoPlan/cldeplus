//
// Created by LE, Duc Anh on 7/18/15.
//

#include "MultiCellsObject.h"

namespace CLDEPlus {
    namespace Relation {

        Foundation::SPtrEntityProxy MultiCellsObject::Refer() {
            return _sptrEntityQuery->Select(_sptrCriteria, _columns).front();
        }

        SPtrMultiCellsObj CreateMultiCellsObj(Foundation::SPtrEntityQuery &entityQuery,
                                              Foundation::Query::SPtrCriteria &criteria,
                                              std::initializer_list<Foundation::SPtrColumn> &columns) {
            return cldeplus_make_shared<MultiCellsObject>(entityQuery, criteria, columns);
        }
    }
}


