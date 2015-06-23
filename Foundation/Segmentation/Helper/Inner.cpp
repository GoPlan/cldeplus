//
// Created by LE, Duc Anh on 6/23/15.
//

#include "Foundation/Comparer/EntityProxyComparer.h"
#include "Inner.h"

namespace Cloude {
    namespace Foundation {

        SPtrEntityProxySet Segmentation::Helper::Inner::operator()(const JoinPhrase &lhs,
                                                                   const JoinPhrase &rhs) const {
            SPtrColumnVector lhsComparingColumns;
            SPtrColumnVector rhsComparingColumns;

            Comparer::EntityProxyComparer compare{lhsComparingColumns, rhsComparingColumns};

            SPtrEntityProxySet setProxies;

            auto lhsIter = lhs.getSetProxies().cbegin();
            auto rhsIter = rhs.getSetProxies().cbegin();

            while (lhsIter != lhs.getSetProxies().cend()) {

                if (rhsIter == rhs.getSetProxies().cend())
                    break;

                while (compare(*lhsIter, *rhsIter)) {

                    SPtrEntityProxy proxy = std::make_shared<EntityProxy>();


                    ++rhsIter;
                }

                ++lhsIter;
            }

            return setProxies;
        }
    }
}


