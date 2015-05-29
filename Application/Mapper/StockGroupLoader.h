//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include "memory"
#include "string"
#include "mysql.h"
#include "../../Architecture/EntityLoader.h"
#include "../Model/StockGroup.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using EntityLoader = Cloude::Architecture::EntityLoader;
            using Entity = Cloude::Architecture::Entity;
            using Identity = Cloude::Architecture::Identity;
            using Column = Cloude::Architecture::Column;
            using Field = Cloude::Architecture::Field;

            class StockGroupLoader : public EntityLoader {
            public:
                StockGroupLoader() = default;
                StockGroupLoader(const StockGroupLoader &srcStockGroupLoader) = default;
                StockGroupLoader &operator=(const StockGroupLoader &srcStockGroupLoader) = default;
                virtual ~StockGroupLoader();

                std::shared_ptr<Identity> NextPrimaryKey() override;
                void LoadEntity(std::shared_ptr<Identity> &identity) override;

            private:
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
