//
// Created by LE, Duc Anh on 6/16/15.
//

#include "Join.h"

namespace Cloude {
    namespace Foundation {

        Segmentation::Join::Join(JoinType joinType, const SPtrTarget &lhs, const SPtrTarget &rhs)
                : _joinType(joinType), _lhs(lhs), _rhs(rhs) {
            //
        }

        void Segmentation::Join::Evaluate() {

        }

        const SPtrEntityProxyVector &Segmentation::Join::ResultSet() const {
            return _resultStorage;
        }
    }
}


