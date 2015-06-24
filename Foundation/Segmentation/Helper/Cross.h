//
// Created by LE, Duc Anh on 6/24/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                struct Cross : public std::binary_function<JoinPhrase, JoinPhrase, bool> {
                public:
                    SPtrEntityProxySet operator()(const JoinPhrase &lhsPhrase, const JoinPhrase &rhsPhrase) const;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_CROSS_H
