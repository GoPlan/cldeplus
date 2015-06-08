//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPMAP_H
#define CLOUD_E_CPLUS_STOCKGROUPMAP_H

#include "Framework/Column.h"
#include "Framework/EntityMap.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            class StockGroupMap : public Framework::EntityMap {
            public:
                StockGroupMap();
                virtual ~StockGroupMap() = default;

                static std::string TableName;

                static std::shared_ptr<Framework::Column> Code;
                static std::shared_ptr<Framework::Column> UniqueName;
                static std::shared_ptr<Framework::Column> DefaultStockCode;

            protected:
                virtual const std::string& TableNameCore() const;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPMAP_H
