//
// Created by LE, Duc Anh on 6/18/15.
//

#include "Target.h"

namespace Cloude {
    namespace Foundation {

        const SPtrEntityProxyVector &Segmentation::Target::ResultSet() const {
            return _resultStorage;
        }

        void Segmentation::Target::Evaluate() {
            _resultStorage = _entityQuery.Compose(_criteria);
        }
    }
}


