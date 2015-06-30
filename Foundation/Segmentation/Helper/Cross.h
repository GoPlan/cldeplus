//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/JoinPhrase.h>
#include <Foundation/Transformation/EntityTransformer.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class Cross {

                    JoinPhrase _lhs;
                    JoinPhrase _rhs;
                    Transformation::EntityTransformer _transformer;

                public:
                    Cross(const JoinPhrase &lhsJoinPhrase, const JoinPhrase &rhsJoinPhrase);
                    SPtrEntityProxySet operator()(const SPtrEntityProxySet &lhs, const SPtrEntityProxySet &rhs) const;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
