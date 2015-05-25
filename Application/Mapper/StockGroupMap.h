//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPMAP_H
#define CLOUD_E_CPLUS_STOCKGROUPMAP_H

#include <Architecture/EntityMap.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using Column = Cloude::Architecture::Column;
            using EntityMap = Cloude::Architecture::EntityMap;

            class StockGroupMap : public EntityMap {
            public:
                static std::shared_ptr<Column> Id;
                static std::shared_ptr<Column> Code;
                static std::shared_ptr<Column> Name;
                static std::shared_ptr<Column> DefaultStockCode;
                static std::string TableName;

                StockGroupMap();
                virtual ~StockGroupMap();

            protected:
                virtual std::string TableNameCore();


            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPMAP_H
