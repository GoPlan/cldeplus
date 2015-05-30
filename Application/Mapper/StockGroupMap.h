//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPMAP_H
#define CLOUD_E_CPLUS_STOCKGROUPMAP_H

#include "Architecture/Column.h"
#include "Architecture/EntityMap.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            class StockGroupMap : public Architecture::EntityMap {
            public:
                StockGroupMap();
                virtual ~StockGroupMap() = default;

                static std::string TableName;

                static std::shared_ptr<Architecture::Column> Id;
                static std::shared_ptr<Architecture::Column> Code;
                static std::shared_ptr<Architecture::Column> Name;
                static std::shared_ptr<Architecture::Column> DefaultStockCode;

            protected:
                virtual const std::string& TableNameCore() const;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPMAP_H
