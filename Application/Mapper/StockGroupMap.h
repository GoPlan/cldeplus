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
                ~StockGroupMap() = default;

                static std::string TableName;

                static Foundation::SPtrColumn Code;
                static Foundation::SPtrColumn UniqueName;
                static Foundation::SPtrColumn DefaultStockCode;

            protected:
                virtual const std::string &TableNameCore() const;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPMAP_H
