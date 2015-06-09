//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include <memory>
#include <string>
#include <mysql.h>
#include <Foundation/EntityLoader.h>
#include <Application/Model/StockGroup.h>

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using EntityLoader = Cloude::Foundation::EntityLoader;
            using Identity = Cloude::Foundation::Identity;

            class StockGroupLoader : public EntityLoader {
            public:
                StockGroupLoader() = default;
                StockGroupLoader(const StockGroupLoader &srcStockGroupLoader) = default;
                StockGroupLoader &operator=(const StockGroupLoader &srcStockGroupLoader) = default;
                virtual ~StockGroupLoader();

                std::shared_ptr<Identity> NextPrimaryKey() const override;

            private:
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
