//
// Created by LE, Duc-Anh on 5/23/15.
//

#ifndef CLOUD_E_CPLUS_ENTITYSTORE_H
#define CLOUD_E_CPLUS_ENTITYSTORE_H

#include "Identity.h"
#include "Entity.h"
#include "EntityMap.h"
#include "EntityLoader.h"

using namespace std;

namespace Cloude {
    namespace Architecture {
        namespace Foundation {

            class EntityStore {
            public:
                EntityStore(EntityMap &entityMap, EntityLoader &entityLoader) : _entityMap(entityMap),
                                                                                _entityLoader(entityLoader) {
                    //
                };

                virtual ~EntityStore() {
                    Clear();
                };

                shared_ptr<Entity> Get(shared_ptr<Identity>& identity);
                shared_ptr<Entity> Create();
                shared_ptr<Entity> Create(shared_ptr<Identity> identity);

                void Insert(shared_ptr<Entity>& entity);
                void Delete(shared_ptr<Entity>& entity);
                void Save(shared_ptr<Entity>& entity) const;
                void Clear();

            protected:
                EntityMap &_entityMap;
                EntityLoader &_entityLoader;

                void LoadEntity(shared_ptr<Entity>& entity) const;

            private:
                unordered_map<shared_ptr<Identity>, shared_ptr<Entity>> _identityMap;

            };
        }
    }
}


#endif //CLOUD_E_CPLUS_ENTITYSTORE_H
