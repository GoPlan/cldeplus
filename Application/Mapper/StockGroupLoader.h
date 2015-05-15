//
// Created by GoPlan on 15/05/2015.
//

#ifndef CLOUD_E_CPLUS_STOCKGROUPLOADER_H
#define CLOUD_E_CPLUS_STOCKGROUPLOADER_H

#include "../../Architecture/Foundation/EntityLoader.h"

using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace Application {
        class StockGroupLoader : EntityLoader {

            virtual Entity *CreateEntityInstance(Identity &ident);
            virtual Identity *NextPrimaryKey();
            virtual void LoadEntity(Entity &entity);
            virtual void EstablishEntityRelationship(Entity &entity);
        };
    }
}


#endif //CLOUD_E_CPLUS_STOCKGROUPLOADER_H
