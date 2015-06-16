//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include <memory>
#include <string>
#include <mysql.h>
#include <Foundation/EntityLoader.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {

            class StockGroupLoader : public Foundation::EntityLoader {
            public:
                StockGroupLoader() = default;
                StockGroupLoader(const StockGroupLoader &srcStockGroupLoader) = default;
                StockGroupLoader &operator=(const StockGroupLoader &srcStockGroupLoader) = default;
                ~StockGroupLoader() = default;

                Foundation::SPtrIdentity NextPrimaryKey() const override;

            private:
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
