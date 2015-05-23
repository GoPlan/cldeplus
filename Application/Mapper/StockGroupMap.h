//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPMAP_H
#define CLOUD_E_CPLUS_STOCKGROUPMAP_H

#include <Architecture/Foundation/EntityMap.h>

using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class StockGroupMap : public EntityMap {

            public:
                static shared_ptr<Column> Id;
                static shared_ptr<Column> Code;
                static shared_ptr<Column> Name;
                static shared_ptr<Column> DefaultStockCode;
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
