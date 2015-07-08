//
// Created by LE, Duc Anh on 7/8/15.
//

#include "LinkToOne.h"

namespace Cloude {
    namespace Relation {

        Foundation::SPtrEntityProxy LinkToOne::Call() {
            return _sptrEntityQuery->SelectFirst(_sptrCriteria);
        }
    }
}


