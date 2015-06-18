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

        const std::string Segmentation::Join::CopyToString() const {
            return __1::basic_string < char, char_traits < char >, allocator < char >> ();
        }
        const std::string &Segmentation::Join::ToString() const {
            return <#initializer#>;
        }
        const char *Segmentation::Join::ToCString() const {
            return nullptr;
        }
    }
}


