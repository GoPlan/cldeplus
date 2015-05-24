//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPMAP_H
#define CLOUD_E_CPLUS_STOCKGROUPMAP_H

#include <Architecture/EntityMap.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class StockGroupMap : public Cloude::Architecture::EntityMap {

            public:
                static std::shared_ptr<Cloude::Architecture::Column> Id;
                static std::shared_ptr<Cloude::Architecture::Column> Code;
                static std::shared_ptr<Cloude::Architecture::Column> Name;
                static std::shared_ptr<Cloude::Architecture::Column> DefaultStockCode;
                static std::string TableName;

                StockGroupMap();
                ~StockGroupMap();

            protected:
                virtual std::string TableNameCore();


            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPMAP_H
