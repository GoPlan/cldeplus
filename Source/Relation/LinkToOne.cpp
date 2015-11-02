//
// Created by LE, Duc Anh on 7/8/15.
//

#include "LinkToOne.h"

namespace CLDEPlus {
    namespace Relation {

        Foundation::SPtrEntityProxy LinkToOne::Refer() {
            return _sptrEntityQuery->SelectFirst(_sptrCriteria);
        }

        SPtrLinkToOne CreateLinkToOne(Foundation::SPtrEntityQuery &entityQuery,
                                      Foundation::Query::SPtrCriteria &criteria) {
            return cldeplus_make_shared<LinkToOne>(entityQuery, criteria);
        }
    }
}


