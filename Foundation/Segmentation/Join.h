//
// Created by LE, Duc Anh on 6/16/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOIN_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOIN_H

#include <Foundation/EntityProxy.h>
#include <Foundation/Query/Criteria.h>
#include "Target.h"
#include "Segment.h"

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            enum class JoinType {
                Inner,
                Left,
                Right,
                Cross
            };

            class Join : public Segment {

                JoinType _joinType;
                SPtrTarget _rhs;
                SPtrTarget _lhs;

            public:
                Join(JoinType joinType, const SPtrTarget &lhs, const SPtrTarget &rhs);
                Join(const Join &) = default;
                Join(Join &&) = default;
                Join &operator=(const Join &) = default;
                Join &operator=(Join &&) = default;
                virtual ~Join() = default;

                // Segment implementation
                virtual void Evaluate() override;
                virtual const SPtrEntityProxyVector &ResultSet() const override;
            };

            using SPtrJoin = std::shared_ptr<Join>;
        }
    }
}

#endif //CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_JOIN_H
