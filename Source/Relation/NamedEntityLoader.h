//
// Created by LE, Duc Anh on 15/05/2015.
//

#ifndef CLDEPLUS_RELATION_NAMEDENTITYLOADER_H
#define CLDEPLUS_RELATION_NAMEDENTITYLOADER_H

#include "../Foundation/Identity.h"
#include "../Foundation/Entity.h"

namespace CLDEPlus {
    namespace Relation {

        template<typename TEntity>
        struct NamedEntityLoader {
            std::function<TEntity(const Foundation::Entity &entity)> fptrNamedEntityCreator;
            std::function<Foundation::SPtrIdentity()> fptrIdentityCreator;
        };
    }
}


#endif //CLDEPLUS_RELATION_NAMEDENTITYLOADER_H
