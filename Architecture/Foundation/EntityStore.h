//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTORE_H
#define CLOUD_E_CPLUS_ENTITYSTORE_H

#include "Identity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            template<class TEntity>
            class EntityStore {

            public:
                EntityStore();

                virtual ~EntityStore();

                virtual TEntity& Get(Identity &identity) = 0;

                virtual TEntity& Create() = 0;

                virtual TEntity& Create(Identity& identity) = 0;

                virtual TEntity& Insert(TEntity& entity) = 0;

                virtual TEntity& Save(TEntity& entity) = 0;

                virtual TEntity& Delete(TEntity& entity) = 0;

            private:

            };
        }
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
