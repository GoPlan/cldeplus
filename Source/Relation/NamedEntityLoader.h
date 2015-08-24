//
// Created by LE, Duc Anh on 15/05/2015.
//

#ifndef CLOUD_E_PLUS_RELATION_NAMEDENTITYLOADER_H
#define CLOUD_E_PLUS_RELATION_NAMEDENTITYLOADER_H

#include <Foundation/Identity.h>
#include <Foundation/Entity.h>

namespace Cloude {
    namespace Relation {

        template<typename TEntity>
        struct NamedEntityLoader {
            std::function<TEntity(const Foundation::Entity &entity)> fptrNamedEntityCreator;
            std::function<Foundation::SPtrIdentity()> fptrIdentityCreator;
        };
    }
}


#endif //CLOUD_E_PLUS_RELATION_NAMEDENTITYLOADER_H
