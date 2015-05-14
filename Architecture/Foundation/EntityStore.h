//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTORE_H
#define CLOUD_E_CPLUS_ENTITYSTORE_H

#include "Identity.h"
#include "Entity.h"

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            template<class TEntity>
            class EntityStore {

            public:
                EntityStore();
                virtual ~EntityStore();

                virtual TEntity &Get(Identity &identity) = 0;
                virtual TEntity &Create() = 0;
                virtual TEntity &Create(Identity &identity) = 0;
                virtual TEntity &Insert(TEntity &entity) = 0;
                virtual TEntity &Save(TEntity &entity) = 0;
                virtual TEntity &Delete(TEntity &entity) = 0;

                bool HasIdentityInMap(Identity &identity);

                void RegisterClean(TEntity &entity);
                void RegisterChanged(TEntity &entity);
                void RegisterDeleted(TEntity &entity);
                void UnRegister(TEntity &entity);
                void Commit();

            protected:
                unordered_map<Identity &, TEntity *> identityMap;
                unordered_map<Identity &, TEntity *> changedMap;
                unordered_map<Identity &, TEntity *> deletedMap;

                virtual Identity *NextPrimaryKey() = 0;
                virtual TEntity *CreateEntityInstance(Identity &identity) = 0;
                virtual void EstablishEntityRelationship(Identity &identity) = 0;

            private:
                void CommitChanged();
                void CommitDeleted();

            };
        }
    }
}

#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
