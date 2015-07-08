//
// Created by LE, Duc Anh on 7/8/15.
//

#include "LinkToMany.h"

namespace Cloude {
    namespace Relation {

        Foundation::SPtrEntityProxyVector LinkToMany::Call() {
            return _sptrEntityQuery->Select(_sptrCriteria);
        }
    }
}


