//
// Created by LE, Duc Anh on 7/8/15.
//

#include "LinkToMany.h"

namespace Cloude {
    namespace Relation {

        Foundation::SPtrEntityProxyVector LinkToMany::Refer() {
            return _sptrEntityQuery->Select(_sptrCriteria);
        }

        SPtrLinkToMany CreateLinkToMany(const Foundation::SPtrEntityQuery &entityQuery,
                                        const Foundation::Query::SPtrCriteria &criteria) {
            return std::make_shared<LinkToMany>(entityQuery, criteria);
        }
    }
}


