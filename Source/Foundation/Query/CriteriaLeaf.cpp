//
// Created by LE, Duc Anh on 6/11/15.
//

#include "CriteriaLeaf.h"

namespace CLDEPlus {
    namespace Foundation {
        namespace Query {

            const SPtrColumn &CriteriaLeaf::getColumn() const {
                return _column;
            }

            const Data::SPtrValue &CriteriaLeaf::getValue() const {
                return _value;
            }

            const bool CriteriaLeaf::isComposite() const {
                return false;
            }
        }
    }
}


