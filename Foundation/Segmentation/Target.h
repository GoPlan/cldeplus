//
// Created by LE, Duc Anh on 6/18/15.
//

#ifndef CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_STORE_H
#define CLOUD_E_PLUS_FOUNDATION_SEGMENTATION_STORE_H

#include <memory>
#include <Foundation/EntityQuery.h>
#include "Segment.h"

namespace Cloude {
    namespace Foundation {
        namespace Segmentation {

            class Target : public Segment {

                using SPtrDisplayColumnPair = std::pair<std::string, Foundation::SPtrColumn>;
                using SPtrDisplayColumnPairVector= std::vector<SPtrDisplayColumnPair>;

                SPtrDisplayColumnPairVector _displayColumns;
                SPtrEntityQuery _entityQuery;
                Query::SPtrCriteria _criteria;

            public:
                Target() = default;
                Target(const Target &) = default;
                Target(Target &&) = default;
                Target &operator=(const Target &) = default;
                Target &operator=(Target &&) = default;
                virtual ~Target() = default;

                // Segment implementation
                virtual void Evaluate() override;
                virtual SegmentType getSegmentType();
                virtual const SPtrEntityProxyVector &ResultSet() const override;

                // Locals
                void AddDisplayColumn(const std::pair<std::string, Foundation::SPtrColumn> &column);
                void ClearDisplayColumns();

                // Accessors & Mutators
                void setEntityQuery(const SPtrEntityQuery &entityQuery) { _entityQuery = entityQuery; }
                void setCriteria(const Query::SPtrCriteria &criteria) { _criteria = criteria; }
            };

            using SPtrTarget = std::shared_ptr<Target>;
        }
    }
}


#endif //CLOUD_E_PLUS_STORE_H
