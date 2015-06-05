//
// Created by LE, Duc Anh on 6/5/15.
//

#include "MongoDbSourceDriver.h"

namespace Cloude {
    namespace Infrastructure {
        namespace MongoDb {

            MongoDbSourceDriver::MongoDbSourceDriver(Architecture::EntityMap &entityMap)
                    : EntitySourceDriver(entityMap) {
                //
            }

            int MongoDbSourceDriver::LoadEntity(std::shared_ptr<Entity> &entity,
                                                const EntityMap &entityMap) const {
                return 0;
            }

            int MongoDbSourceDriver::CreateEntity(std::shared_ptr<Entity> &entity,
                                                  const EntityMap &entityMap) const {
                return 0;
            }

            int MongoDbSourceDriver::SaveEntity(std::shared_ptr<Entity> &entity,
                                                const EntityMap &entityMap) const {
                return 0;
            }

            int MongoDbSourceDriver::DeleteEntity(std::shared_ptr<Entity> &entity,
                                                  const EntityMap &entityMap) const {
                return 0;
            }

            void MongoDbSourceDriver::Connect() {

            }

            void MongoDbSourceDriver::Disconnect() {

            }

            void MongoDbSourceDriver::init() {

            }
        }
    }
}


