//
// Created by LE, Duc Anh on 7/8/15.
//

#include "LinkToMany.h"

namespace CLDEPlus {
    namespace Relation {

        Foundation::SPtrEntityProxyVector LinkToMany::Refer() {
            return _sptrEntityQuery->Select(_sptrCriteria);
        }

        SPtrLinkToMany CreateLinkToMany(Foundation::SPtrEntityQuery &entityQuery,
                                        Foundation::Query::SPtrCriteria &criteria) {
            return cldeplus_make_shared<LinkToMany>(entityQuery, criteria);
        }
    }
}


