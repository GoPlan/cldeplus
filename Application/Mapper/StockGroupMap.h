//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPMAP_H
#define CLOUD_E_CPLUS_STOCKGROUPMAP_H

#include "../../Architecture/Foundation/EntityMap.h"

using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class StockGroupMap : public EntityMap {

            public:
                static Column Id;
                static Column Code;
                static Column Name;
                static Column DefaultStockCode;
                static string TableName;

                StockGroupMap();
                ~StockGroupMap();

            protected:
                virtual string TableNameCore();


            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPMAP_H
