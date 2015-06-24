//
// Created by LE, Duc Anh on 6/24/15.
//

#include <Foundation/Comparer/EntityProxyComparer.h>
#include "Cross.h"

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                SPtrEntityProxySet Cross::operator()(const JoinPhrase &lhsPhrase, const JoinPhrase &rhsPhrase) const {

                    Comparer::EntityProxyComparer compare{lhsPhrase.getVectorComparingColumns(),
                                                          rhsPhrase.getVectorComparingColumns()};

                    SPtrEntityProxySet setProxies;
                    auto lhsIter = lhsPhrase.getSetProxies().cbegin();
                    auto rhsIter = rhsPhrase.getSetProxies().cbegin();




                    return setProxies;
                }
            }
        }
    }
}


