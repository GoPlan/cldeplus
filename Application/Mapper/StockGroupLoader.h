//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include "memory"
#include "string"
#include "mysql.h"
#include "../../Framework/EntityLoader.h"
#include "../Model/StockGroup.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using EntityLoader = Cloude::Framework::EntityLoader;
            using Entity = Cloude::Framework::Entity;
            using Identity = Cloude::Framework::Identity;
            using Column = Cloude::Framework::Column;
            using Field = Cloude::Framework::Field;

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
