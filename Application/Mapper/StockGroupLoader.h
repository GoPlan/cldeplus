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
            class StockGroupLoader : public Cloude::Architecture::EntityLoader {
            public:
                std::unique_ptr<Cloude::Architecture::Entity> CreateEntityInstance(std::shared_ptr<Cloude::Architecture::Identity> ident) override;
                std::unique_ptr<Cloude::Architecture::Identity> NextPrimaryKey() override;
                void LoadEntity(Cloude::Architecture::Entity &entity) override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
