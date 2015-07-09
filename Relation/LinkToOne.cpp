//
// Created by LE, Duc Anh on 7/8/15.
//

#include "LinkToOne.h"

namespace Cloude {
    namespace Relation {

        Foundation::SPtrEntityProxy LinkToOne::Call() {
            return _sptrEntityQuery->SelectFirst(_sptrCriteria);
        }

        SPtrLinkToOne CreateLinkToOne(const Foundation::SPtrEntityQuery &entityQuery,
                                      const Foundation::Query::SPtrCriteria &criteria) {
            return std::make_shared<LinkToOne>(entityQuery, criteria);
        }
    }
}


