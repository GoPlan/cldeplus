//
// Created by LE, Duc Anh on 6/23/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_JOINFUNCTOR_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_JOINFUNCTOR_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Segmentation/JoinPhrase.h>

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {
            namespace Helper {

                class JoinFunctor {

                public:
                    JoinFunctor() = default;
                    JoinFunctor(const JoinFunctor &) = default;
                    JoinFunctor(JoinFunctor &&) = default;
                    JoinFunctor &operator=(const JoinFunctor &) = default;
                    JoinFunctor &operator=(JoinFunctor &&) = default;
                    virtual ~JoinFunctor() = default;

                    virtual SPtrEntityProxySet operator()(const JoinPhrase &lhs, const JoinPhrase &rhs) = 0;
                };
            }
        }
    }
}


#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_HELPER_JOINFUNCTOR_H
