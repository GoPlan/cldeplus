//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPMAP_H
#define CLOUD_E_CPLUS_STOCKGROUPMAP_H

#include "Foundation/Column.h"
#include "Foundation/EntityMap.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            class StockGroupMap : public Foundation::EntityMap {
            public:
                StockGroupMap();
                virtual ~StockGroupMap() = default;

                static std::string TableName;

                static std::shared_ptr<Foundation::Column> Code;
                static std::shared_ptr<Foundation::Column> UniqueName;
                static std::shared_ptr<Foundation::Column> DefaultStockCode;

            protected:
                virtual const std::string& TableNameCore() const;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPMAP_H
