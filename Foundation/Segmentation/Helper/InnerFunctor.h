//
// Created by LE, Duc Anh on 6/23/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_INNERFUNCTOR_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_INNERFUNCTOR_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class InnerFunctor {
                    InnerFunctor() = delete;
                    InnerFunctor(const InnerFunctor &) = delete;
                    InnerFunctor(InnerFunctor &&) = delete;
                    InnerFunctor &operator=(const InnerFunctor &) = delete;
                    InnerFunctor &operator=(InnerFunctor &&) = delete;
                    virtual ~InnerFunctor() = delete;

                public:
                    SPtrEntityProxySet operator()(const JoinPhrase &lhs, const JoinPhrase &rhs) const;

                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_INNERFUNCTOR_H
