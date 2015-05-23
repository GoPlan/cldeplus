//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include "../../Architecture/Foundation/EntityLoader.h"
#include "../Model/StockGroup.h"

using namespace Cloude::Architecture::Foundation;
using namespace Cloude::Application::Model;

namespace Cloude {
    namespace Application {
        namespace Mapper {
            class StockGroupLoader : public EntityLoader {
            public:
                shared_ptr<Entity> CreateEntityInstance(shared_ptr<Identity> ident) override;
                shared_ptr<Identity> NextPrimaryKey() override;
                void LoadEntity(Entity &entity) override;
            };
        }
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
