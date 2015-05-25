//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include "../../Architecture/EntityLoader.h"
#include "../Model/StockGroup.h"

namespace Cloude {
    namespace Application {
        namespace Mapper {

            using EntityLoader = Cloude::Architecture::EntityLoader;
            using Entity = Cloude::Architecture::Entity;
            using Identity = Cloude::Architecture::Identity;

            class StockGroupLoader : public EntityLoader {
            public:
                virtual ~StockGroupLoader();
                std::unique_ptr<Entity> CreateEntityInstance(std::shared_ptr<Identity> ident) override;
                std::unique_ptr<Identity> NextPrimaryKey() override;
                void LoadEntity(Entity &entity) override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
