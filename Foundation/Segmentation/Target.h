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

                SPtrColumnVector _selectedColumns;
                EntityQuery _entityQuery;
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
                virtual const SPtrEntityProxyVector &ResultSet() const override;

                // Locals
                const SPtrColumnVector &getSelectedColumns() const {
                    return _selectedColumns;
                }
                void setSelectedColumns(const SPtrColumnVector &selectedColumns) {
                    Target::_selectedColumns = selectedColumns;
                }
            };

            using SPtrTarget = std::shared_ptr<Target>;
        }
    }
}


#endif //CLOUD_E_PLUS_STORE_H
