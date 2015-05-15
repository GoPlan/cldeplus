//
// Created by GoPlan on 14/05/2015.
//

#ifndef CLOUD_E_CPLUS_MYSQLENTITYSTORE_H
#define CLOUD_E_CPLUS_MYSQLENTITYSTORE_H

#include "../Architecture/Foundation/EntityStore.h"

using namespace Cloude::Architecture::Foundation;

namespace Cloude {
    namespace Infrastructure {

        template<class TEntity>
        class MySqlEntityStore : EntityStore<TEntity> {
        public:
            MySqlEntityStore(EntityMap &entityMap) : EntityStore<TEntity>(entityMap) { };
            virtual ~MySqlEntityStore(){};
        };

    }
}


#endif //CLOUD_E_CPLUS_MYSQLENTITYSTORE_H
