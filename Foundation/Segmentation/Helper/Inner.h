//
// Created by LE, Duc Anh on 6/23/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_INNER_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_INNER_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class Inner {

                    Inner() = delete;
                    Inner(const Inner &) = delete;
                    Inner(Inner &&) = delete;
                    Inner &operator=(const Inner &) = delete;
                    Inner &operator=(Inner &&) = delete;
                    ~Inner() = delete;

                public:
                    SPtrEntityProxySet operator()(const JoinPhrase &lhsPhrase, const JoinPhrase &rhsPhrase) const;

                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_INNER_H
